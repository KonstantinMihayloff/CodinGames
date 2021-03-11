#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <vector>


using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

typedef pair<int, int> Coordinates;

vector<Coordinates> getFlatAreaCoordinates(vector<Coordinates> coordList)
{
    Coordinates previousCoord;
    Coordinates currentCoord;

    for (auto coord : coordList)
    {
        if (coordList[0] != coord) {
            cerr << coord.first << " " << coord.second << endl;
            cerr << previousCoord.first << " " << previousCoord.second << endl;
            cerr << " ----- " << endl;
            if (coord.second == previousCoord.second) {

                currentCoord.first = coord.first;
                currentCoord.second = coord.second;
                break;
            }
        }

        previousCoord.first = coord.first;
        previousCoord.second = coord.second;
    }

    vector<Coordinates> result{ previousCoord, currentCoord };
    return result;
}

int main()
{
    int surfaceN; // the number of points used to draw the surface of Mars.
    cin >> surfaceN; cin.ignore();

    vector<Coordinates> marsCoord;
    //pair<int, int> marsCoord[surfaceN];

    for (int i = 0; i < surfaceN; i++) {
        int landX; // X coordinate of a surface point. (0 to 6999)
        int landY; // Y coordinate of a surface point. By linking all the points together in a sequential fashion, you form the surface of Mars.
        cin >> landX >> landY; cin.ignore();

        // Get Mars coordinates that describe the landscape
        marsCoord.insert(marsCoord.end(), Coordinates(landX, landY));
    }

    // Find the landing spot
    vector<Coordinates> landingAreaCoord = getFlatAreaCoordinates(marsCoord);
    // DEBUG
    cerr << landingAreaCoord[0].first << " " << landingAreaCoord[0].second << endl;
    cerr << landingAreaCoord[1].first << " " << landingAreaCoord[1].second << endl;

    // game loop
    while (1) {
        int X;
        int Y;
        int hSpeed; // the horizontal speed (in m/s), can be negative.
        int vSpeed; // the vertical speed (in m/s), can be negative.
        int fuel; // the quantity of remaining fuel in liters.
        int rotate; // the rotation angle in degrees (-90 to 90).
        int power; // the thrust power (0 to 4).
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore();

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        // rotate power. rotate is the desired rotation angle. power is the desired thrust power.
        cout << "-20 3" << endl;
    }
}