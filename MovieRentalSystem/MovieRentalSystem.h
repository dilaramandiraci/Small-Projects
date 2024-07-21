#pragma once
#include <string>
#include "Movie.h"
#include "Subscriber.h"
using namespace std;

class MovieRentalSystem {
public:
        MovieRentalSystem(const string movieInfoFileName ,const string subscriberInfoFileName );
        MovieRentalSystem( );
        ~MovieRentalSystem();
        void removeMovie( const int movieId ); //remove için sayı okey yoksa removelayamaz
        void addMovie( const int movieId, const int numCopies ); //3 tane eklenebilir
        void removeSubscriber( const int subscriberId ); //ok
        void rentMovie( const int subscriberId, const int movieId ); 
        void returnMovie( const int subscriberId, const int movieId );
        void showMoviesRentedBy( const int subscriberId ) const;
        void showSubscribersWhoRentedMovie( const int movieId ) const;
        void showAllMovies() const;
        void showAllSubscribers() const;
private:

        Node<Movie>* MovieHead;
        int movieNum;

        Node<Subscriber>* Subshead;
        int subsNum;
};