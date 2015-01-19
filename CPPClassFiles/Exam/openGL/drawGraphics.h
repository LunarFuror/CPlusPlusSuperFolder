#include <GL/glut.h>
#include <GL/freeglut.h>
#include <string>

class drawGraphics{
	public:
		drawGraphics();
		void drawCursor();          //little arrow that will move, each menu will probably have set positions
		void drawBattleMenu();      //the bottom right box in the battle scene to choose an action
		void drawMessage();         //the bottom left box in the battle scene probably 4 or 5 lines
		void drawGameMenu();        /*draw the menu box, probably have options and such, selecting these will either
																  change the text or open another window.*/
		void drawCharacterInfo();   //draw a window that has the characters stats and such
		void drawCharacter();       //draw you, probably just a box with a texture
		void drawEnemy();           //draw the enemies sprite, probably just a box with a texture
		void drawCharacterHealth(); //draw your health
		void drawEnemyHealth();     //draw the enemies health
		void drawBackWindow();      //draw the background window, this should always be there
		void drawBattleSpace();     //Background of the fight
		void drawBox(double, double, double, double); //Draw a box with top left corner at x and y, with a height and width
		void setBoxColor(double, double, double);     //Sets the color of the box that will be drawn (0 to 255)
		void setBoxTexture();		//Set's the texture of the textureBox that will be drawn
		void drawTextureBox();  //Draws a box with a texture
		void drawCompass();

		void setX(double);
		void setY(double);
		void setZ(double);
		double getX();
		double getY();
		double getZ();

	private:
		int cursorPosition;
		int menuType;
		double red;
		double blue;
		double green;
		double x1;
		double y1;
		double z1;
};
