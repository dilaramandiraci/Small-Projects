#include "LeagueManagementSystem.h"
#include <iostream>
using namespace std;

int main()
{
    LeagueManagementSystem LMS;
    LMS.showAllTeams();
    cout << endl;

    LMS.addTeam("Fenerbahce", 1907); 
    LMS.addTeam("Tofas", 1957);
    LMS.addTeam("Anadolu Efes", 1951);
    LMS.removeTeam("Tofas");
    LMS.addTeam("Darussafaka", 1951);
    LMS.addTeam("Fenerbahce", 1907); 
    LMS.removeTeam("Tofas");         
    cout << endl;

    LMS.addPlayer("Fenerbahce", "Melih Mahmutoglu", 10, 2000000);
    LMS.addPlayer("Fenerbahce", "Sehmus Hazer", 2, 1000000);
    LMS.addPlayer("Darussafaka", "Ercan Osmani", 6, 1000000);
    LMS.addPlayer("Anadolu Efes", "Dogus Balbay", 4, 1000000);
    LMS.addPlayer("Anadolu Efes", "Bugrahan Tuncer", 10, 1500000);
    LMS.removePlayer("Darussafaka", "Ercan Osmani");

    cout << endl;

    LMS.addPlayer("Fenerbahce", "Stephen Curry", 10, 10000000);
    LMS.addPlayer("Karsiyaka", "Metecan Birsen", 1, 1000000);
    LMS.addTeam("Karsiyaka", 1912);
    LMS.addPlayer("Karsiyaka", "Metecan Birsen", 1, 1000000);
    LMS.removePlayer("Tofas", "Melih Mahmutoglu");
    LMS.removePlayer("Fenerbahce", "Bugrahan Tuncer");
    LMS.transferPlayer( "Metecan Birsen", "Karsiyaka", "Fenerbahce" );
    LMS.transferPlayer( "Lebron James", "Los Angeles Lakers", "Fenerbahce" );
    LMS.transferPlayer( "Michael Jordan", "Darussafaka", "Fenerbahce" );
    LMS.transferPlayer( "Bugrahan Tuncer", "Anadolu Efes", "Fenerbahce" );
    cout << endl;

    LMS.showAllTeams();
    cout << endl;
    LMS.showTeam( "Fenerbahce" );
    cout << endl;
    LMS.showTeam( "Boston Celtics" );
    cout << endl;
    LMS.showPlayer( "Melih Mahmutoglu" );
    cout << endl;
    LMS.showPlayer( "Furkan Korkmaz" );  

    return 0;
}