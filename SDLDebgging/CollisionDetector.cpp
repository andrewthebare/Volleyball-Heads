#include "CollisionDetector.h"

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
		 std::cout << "NO COLLISION" << endl;
		 return false;
	 }
	 else {
		 std::cout << "Collission" << endl;
		 return true;
	 }
}