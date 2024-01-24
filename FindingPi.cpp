#include <iostream>
#include <random>
#include <cmath>
using namespace std;


// Below I wrote a program calculating pi based on a dart game

// Let's say we have a circle of radius 1 that is centered on a square with an area of 4,
// so the radius of the circle touches the center of each side of the square.

// For an infinite number of darts, the ratio between the total darts and the darts that land
// in the circle equals the ratio between the area of the square (4) and the area of the circle.

// We can't find the exact value of this ratio (or else the program would run forever), but we
// can approximate it for a very large number of darts. Since we know that the area of a circle is
// pi * r^2, where r is the radius of the circle, we can use the ratio above to find the area of the circle,
// and find pi = area / r^2.

//I got this problem from MIT Open Courseware

double findPi(int darts){

    //random number generator
    int N = 1000;
    int counter = 0;
    int inCircle = 0;
    double d, area;
    std::random_device seed;
    std:: mt19937 gen(seed());
    std::uniform_int_distribution<> randomNumber(1,N);

    while (counter < darts){
        counter++;
        // random point inside the square
        double x = (double(randomNumber(gen))) / N;
        double y = (double(randomNumber(gen))) / N;

        // distance from the center of the circle to the point, is it within the radius?
        d = sqrt( pow(x,2) + pow(y,2));
        if (d < 1)
            inCircle++;
    }

    // area of circle using the ratio total_darts/darts_in_circle = 4/area_of_circle

    area = (double)(4 * inCircle) / darts;

    // since in our case r = 1 , area/r^2 is just area, so
    // we can take pi = area of the circle
    return area;

}

int main() {
    double pi = 3.1415926535;
    cout << "Accepted value for pi: " << pi << endl;

    int dart = 10;
    cout << "Approximating pi for a small number of darts: " << findPi(dart) << endl;

    dart = 5000000;
    cout << "Approximating pi for a very large number of darts: " << findPi(dart) << endl;

    // as we increase the number of darts, our approximation for pi grows closer to the
    // accepted value for pi because our ratio is more accurate

    return 0;
}

