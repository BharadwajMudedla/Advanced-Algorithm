#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <set>
#include <algorithm>
using namespace std;

unordered_map<char, unordered_map<char, int>> cityMap = {
    {'A', {{'B', 10}, {'E', 3}}},
    {'B', {{'C', 2}, {'E', 4}}},
    {'C', {{'D', 9}}},
    {'D', {{'C', 7}}},
    {'E', {{'B', 1}, {'C', 8}}}
};

char chooseNextCity(const unordered_map<char, int>& travelCost, const set<char>& visitedCities) {
    int bestCost = numeric_limits<int>::max();
    char bestCity = '\0';

    for (const auto& entry : travelCost) {
        char city = entry.first;
        int cost = entry.second;
        if (visitedCities.find(city) == visitedCities.end() && cost < bestCost) {
            bestCost = cost;
            bestCity = city;
        }
    }
    return bestCity;
}

pair<int, vector<char>> findShortestRoute(char startCity, char destinationCity) {
    unordered_map<char, int> travelCost;
    unordered_map<char, char> previousCity;
    set<char> visitedCities;

    for (const auto& entry : cityMap) {
        travelCost[entry.first] = numeric_limits<int>::max();
    }
    travelCost[startCity] = 0;

    while (visitedCities.size() < cityMap.size()) {
        char currentCity = chooseNextCity(travelCost, visitedCities);
        if (currentCity == '\0') break;

        visitedCities.insert(currentCity);

        for (const auto& road : cityMap[currentCity]) {
            char neighborCity = road.first;
            int roadCost = road.second;

            if (visitedCities.find(neighborCity) == visitedCities.end()) {
                int newCost = travelCost[currentCity] + roadCost;
                if (newCost < travelCost[neighborCity]) {
                    travelCost[neighborCity] = newCost;
                    previousCity[neighborCity] = currentCity;
                }
            }
        }

        if (currentCity == destinationCity) break;
    }

    vector<char> route;
    int totalTravelCost = travelCost[destinationCity];

    if (totalTravelCost == numeric_limits<int>::max()) {
        return {totalTravelCost, {}};  
    }

    for (char city = destinationCity; city != startCity; city = previousCity[city]) {
        if (previousCity.find(city) == previousCity.end()) return {numeric_limits<int>::max(), {}};
        route.push_back(city);
    }
    route.push_back(startCity);
    reverse(route.begin(), route.end());

    return {totalTravelCost, route};
}

int main() {
    char startCity, destinationCity;

    cout << "Enter starting city (A-E): ";
    cin >> startCity;
    cout << "Enter destination city (A-E): ";
    cin >> destinationCity;

    startCity = toupper(startCity);
    destinationCity = toupper(destinationCity);

    if (cityMap.find(startCity) == cityMap.end() || cityMap.find(destinationCity) == cityMap.end()) {
        cout << "Error: City not found in the map.\n";
        return 1;
    }

    auto result = findShortestRoute(startCity, destinationCity);

    if (!result.second.empty()) {
        cout << "Best route: ";
        for (char city : result.second) cout << city << " ";
        cout << "\nTotal travel cost: " << result.first << endl;
    } else {
        cout << "No route exists between " << startCity << " and " << destinationCity << ".\n";
    }

    return 0;
}
