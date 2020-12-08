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
		 std::cout << "Collission" << endl;
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

	 int radiusA = rectA.w / 2;


	 //get the angle away
	 return false;

 }

 double CollisionDetector::CalculateAngle(pair<int, int> centerA, pair<int, int> centerB) {
	 double x, y;

	 x = centerA.first - centerB.first;
	 y = centerA.second - centerB.second;

	 return tan(x / y);
 }