#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string d = "Godzilla terrorizes Bajtoly lower again. Every day a monster comes out of the ocean, slow movement of marching through the city to some of the skyscrapers and eats it with people who are in it. Eating one skyscraper takes the whole day, at dusk, it returns to its hiding place hidden in the depths. To make maters worse, going through the city, Godzilla wags its tail and destroys towers, near the passes. The prospect of becoming a meal for an underwater monster, to discourage some residents spent in uncomfort- tion in the city. During the night of each tower is derived as a resident and fles to the countryside. In Bajtogrodzie skyscrapers were built only at street crossings. At each intersection there is exactly one building. Junctions are connected by two-way streets. In addition, a the junction is just above the ocean, this is where Godzilla begins its destructive journey through the city. During the investigation, the monster moves only in the streets. Godzilla noted that he must hurry up with the consumption of residents and carefully choose the skyscrapers devouring and streets, which reaches them. Of course, choosing never previously consumed or destroyed- wanego skyscraper. What is the maximum number of people who can eat before the city completely desolate? Entrance The first line of standard input contains two integers him (1 n 10 0, 0 50 0 m) respectively denoting the number of intersections in the city and the number of connecting streets. Crossroads numbers are numbered from 1 to n, junction 1 is located on the shores of the ocean. Next row contains a sequence of integers n s (0 s 10 0) to describe population skyscrapers at various intersections. In each of the next m rows are the two integers ai and bi (1 ai, bi n, ai = bi), which means that there is a road junction connecting ai and bi. The crossing number One can reach any other intersection in the city. Exit Write to std";
    d += "out the number of people who eat Godzilla for the optimum choice of meals and roads through the city every day. Example For input: the result is correct: 5 5 1 1 3 2 4 7 1 2 1 3 2 3 2 4 3 5";

    ofstream file;
    file.open("1.txt");

    ifstream df;
    df.open("gen1.out");
    
    string t;
    getline(df, t);

    string ans = "";
    for (int i = 0; i < t.length(); i++) {
        int val = (2932 - (i*i)) % 2932;
        if (val <= 0) val += 2932;

        ans += t[i];
        i += val;
    }

    cout << ans;
}