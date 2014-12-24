#include "Board.h"

Board::Board(vector<vector<PieceData> > b){
	this->board = b;
	this->piece = Piece();
}


void Board::draw(){
	//desenhar tabuleiro + pe�as
	for (unsigned int i = 0; i < board.size(); i++){
		int offsetX = abs(board[i][0].getY());
		int offsetZ = board[i][0].getY()*2;
		glPushMatrix();
			glPushName(board[i][0].getY());
			glTranslated(offsetX, 0, offsetZ); //ajustar linha vertical e horizontalmente
			
			for (unsigned int j = 0; j < board[i].size(); j++){
				//board[i][j].print();
				int offsetXpeca = 2*j;

				//tabuleiro	
				glPushMatrix();
					glTranslated(offsetXpeca, -0.5, 0);
					piece.draw(false, "tabuleiro");
				glPopMatrix();
			
				//pe�as
				if (board[i][j].getTipo() != "vazia"){				
					glPushMatrix();
						glPushName(board[i][j].getX());
						glTranslated(offsetXpeca, 0, 0);
						piece.draw(board[i][j].getCor(), board[i][j].getTipo());
						glPopName();
					glPopMatrix();
				}
			}
			glPopName();
		glPopMatrix();
	}
	
}