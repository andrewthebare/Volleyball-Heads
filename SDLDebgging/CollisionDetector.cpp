#include "CollisionDetector.h"
#include<math.h>

CollisionDetector::CollisionDetector() {
	std::cout << "COL";
}
CollisionDetector::~CollisionDetector() {

}

 bool CollisionDetector::RectangleCollision(SDL_Rect rectA, SDL_Rect rectB) {

	 if (rectA.x + rectA.w < rectB.x
		 || rectA.x > rectB.x+rectB.w
		 || rectA.y+rectA.h < rectB.y
		 || rectA.y > rectB.y + rectB.h) {
		 return false;
	 }
	 else {
		 return true;
	 }
}

 bool CollisionDetector::CircleCollission(SDL_Rect rectA, SDL_Rect rectB) {
	 pair<int, int> centerA;
	 centerA.first = (rectA.x + rectA.w) / 2;
	 centerA.second = (rectA.y + rectA.h) / 2;

	 pair<int, int> centerB;
	 centerB.first = (rectB.x + rectB.w) / 2;
	 centerB.second = (rectB.y + rectB.h) / 2;


	 int x = (centerA.first - centerB.first)/2;
	 int y = (centerA.second - centerB.second)/2;

	 //get the angle away
	 return false;

 }

 double CollisionDetector::CalculateAngle(pair<int, int> centerA, pair<int, int> centerB) {
	 double x, y;

	 x = centerA.first - centerB.first;
	 y = centerA.second - centerB.second;

	 return tan(x / y);
 }

 pair<int, int> CollisionDetector::CalculateAngle(SDL_Rect rectA, SDL_Rect rectB, int xVelA, int yVelA, int xVelB, int yVelB){
	 pair<int, int> centerA;
	 centerA.first = (rectA.x + (rectA.w / 2));
	 centerA.second = (rectA.y + (rectA.h / 2));

	 pair<int, int> centerB;
	 centerB.first = (rectB.x + (rectB.w / 2));
	 centerB.second = (rectB.y + (rectB.h / 2));

	 std::cout << "A: " << xVelA << " " << yVelA << endl << "B: " << xVelB << " " << yVelB << endl;
	 cout << "X's: " << centerA.first - centerB.first << endl;

	 int x = (centerA.first - centerB.first) + xVelB*.5 + (xVelA*-.8);
	 int y = (centerA.second - centerB.second)+yVelB * .5 + (yVelA*-.8);

	 return  pair<int, int>(x, y);
 }
