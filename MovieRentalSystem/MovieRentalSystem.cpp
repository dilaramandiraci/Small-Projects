#include "MovieRentalSystem.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

MovieRentalSystem::MovieRentalSystem(const string movieInfoFileName, const string subscriberInfoFileName)
{
        MovieHead = nullptr;
        Subshead = nullptr;

        movieNum = 0;
        subsNum = 0;

        // adding subscribers to sthe system
        // Declare variables
        string fileName1 = subscriberInfoFileName;
        int subscriberId;
        ifstream inputFileSubs;

        // Open the stream for the input file
        inputFileSubs.open(fileName1.c_str(), ios_base::in);
        inputFileSubs >> subsNum;

        // Continue until the end of the file
        while (inputFileSubs.eof() == false)
        {

                // Read a number from the file stream just like reading from cin
                inputFileSubs >> subscriberId;

                Subscriber subs(subscriberId);
                Node<Subscriber> *eklenecek = new Node<Subscriber>(subs); // BÖYLE Mİ VERİLMELİ???

                Node<Subscriber> *curr = Subshead;
                Node<Subscriber> *prev = nullptr;
                while ((curr != nullptr) && subscriberId > (curr->item.subscriberId))
                {
                        prev = curr;
                        curr = curr->next;
                }

                if (prev == nullptr)
                {
                        eklenecek->next = Subshead;
                        Subshead = eklenecek;
                }
                else
                {
                        eklenecek->next = curr;
                        prev->next = eklenecek;
                }
        }
        // Close the input file stream
        inputFileSubs.close();

        // adding movies to the system
        string fileName2 = movieInfoFileName;
        int movieId;
        int copyno;
        ifstream inputFileMovie;

        // Open the stream for the input file
        inputFileMovie.open(fileName2.c_str(), ios_base::in);

        inputFileMovie >> movieNum;

        // Continue until the end of the file
        while (inputFileMovie.eof() == false)
        {

                // Read a number from the file stream just like reading from cin
                inputFileMovie >> movieId;
                inputFileMovie >> copyno;

                Movie addedMovie(movieId, copyno); // BÖYLE Mİ VERİLMELİ???
                Node<Movie> *eklenecek = new Node<Movie>(addedMovie);
                // eklenecek->item = addedMovie;

                Node<Movie> *curr = MovieHead;
                Node<Movie> *prev = nullptr;

                while ((curr != nullptr) && movieId > (curr->item.id))
                {

                        prev = curr;
                        curr = curr->next;
                }

                if (prev == nullptr)
                {
                        eklenecek->next = MovieHead;
                        MovieHead = eklenecek;
                }
                else
                {
                        eklenecek->next = curr;
                        prev->next = eklenecek;
                }
        }
        // Close the input file stream
        inputFileMovie.close();

        cout << subsNum << " subscribers and " << movieNum << " movies have been loaded" << endl;
}

MovieRentalSystem::~MovieRentalSystem()
{
        Node<Movie> *currmov = MovieHead;
        while (currmov != nullptr)
        {
                currmov = MovieHead->next;
                delete MovieHead;
                MovieHead = currmov;
        }

        Node<Subscriber> *currsubs = Subshead;
        while (currsubs != nullptr)
        {
                currsubs = Subshead->next;
                delete Subshead;
                Subshead = currsubs;
        }

        // iki listeyi de sil. actions?
        // onu da subs ın içinde sil ++++++ . //movienin içinde sil.
}

void MovieRentalSystem::removeMovie(const int movieId)
{
        bool movieExist = false;
        bool uygun = false;
        Node<Movie> *currptr = MovieHead;
        Node<Movie> *prevptr = nullptr;

        while (currptr != nullptr)
        {
                if ((currptr->item.id) == movieId)
                {
                        movieExist = true;
                        if ((currptr->item.origCopyNo) == (currptr->item.mevcutcopy))
                        {
                                uygun = true;
                        }
                }

                if (movieExist && uygun)
                {
                        if (currptr == MovieHead)
                        {
                                MovieHead = currptr->next;
                                delete currptr;
                        }

                        else
                        {
                                prevptr->next = currptr->next;
                                delete currptr;
                        }
                        break; // YENİ
                }
                prevptr = currptr;
                currptr = currptr->next;
        }

        if (!movieExist)
        {
                cout << "Movie " << movieId << " does not exist" << endl;
        }
        if (movieExist && !uygun)
        {
                cout << "Movie " << movieId << " cannot be removed -- at least one copy has not been returned" << endl;
        }

        if (movieExist && uygun)
        {
                cout << "Movie " << movieId << " has been removed" << endl;
        }

        // id si eşit olanı sil
        // original number of copy = available number of copy.
}

void MovieRentalSystem::addMovie(const int movieId, const int numCopies)
{

        Movie addedMovie(movieId, numCopies); // BÖYLE Mİ VERİLMELİ???
        Node<Movie> *eklenecek = new Node<Movie>(addedMovie);
        // eklenecek->item = addedMovie;

        Node<Movie> *curr = MovieHead;
        Node<Movie> *prev = nullptr;

        while ((curr != nullptr) && movieId > (curr->item.id))
        {

                prev = curr;
                curr = curr->next;
        }

        if (prev == nullptr)
        {
                eklenecek->next = MovieHead;
                MovieHead = eklenecek;
        }
        else
        {
                eklenecek->next = curr;
                prev->next = eklenecek;
        }

        cout << "Movie " << movieId << " has been added" << endl;

        // movienin içinde kopya sayısı bilgisini tut.
        // yeni bir tane obje açıp onu sıralı bir şekilde ekle.
}
void MovieRentalSystem::removeSubscriber(const int subscriberId)
{
        // find subscriber
        bool subsExist = false;
        bool canRemovable = false;
        Node<Subscriber> *subscurr = Subshead;
        Node<Subscriber> *subsprev = nullptr;

        while (subscurr != nullptr)
        {
                if ((subscurr->item.subscriberId) == subscriberId)
                {
                        subsExist = true;
                        if (subscurr->item.canSubsRemoveFromSystem())
                        {
                                canRemovable = true;
                        }
                }

                if (subsExist && canRemovable)
                {
                        if (subscurr == Subshead)
                        {
                                Subshead = subscurr->next;
                                delete subscurr;
                        }
                        else
                        {
                                subsprev->next = subscurr->next;
                                delete subscurr;
                        }
                        break; // YENİ
                }

                subsprev = subscurr;
                subscurr = subscurr->next;
        }

        if (canRemovable)
        {
                cout << "Subscriber " << subscriberId << " has been removed" << endl;

                Node<Movie> *currmov = MovieHead;
                while (currmov != nullptr)
                {
                        currmov->item.deleteSubsFromActions(subscriberId);
                        currmov = currmov->next;
                }
        }
        if (subsExist && !canRemovable)
        {
                cout << "Subscriber " << subscriberId << " cannot be removed -- at least one movie has not been returned" << endl;
        }

        if (!subsExist)
        {
                cout << "Subscriber " << subscriberId << " does not exist" << endl;
        }
        // id si eşit olanı sil //elinde movie olmayacak. subscriberin moviesi olmalı mı?
}

void MovieRentalSystem::rentMovie(const int subscriberId, const int movieId)
{
        // hem movie ye ait rent report hem de o subscribera ait rent report yenilenmeli

        // find movie
        bool movieExist = false;
        bool movieuygun = false;
        Node<Movie> *movcurr = MovieHead;

        while (movcurr != nullptr)
        {
                if ((movcurr->item.id) == movieId) // movie var mı?
                {
                        movieExist = true;
                        if (movcurr->item.mevcutcopy > 0) // movie varsa yeterli kopya var mı
                        {
                                movieuygun = true;
                                break;
                        }
                }
                movcurr = movcurr->next;
        }

        // find subscriber
        bool subsExist = false;
        Node<Subscriber> *subscurr = Subshead;

        while (subscurr != nullptr)
        {
                if ((subscurr->item.subscriberId) == subscriberId)
                {
                        subsExist = true;
                        break;
                }
                subscurr = subscurr->next;
        }

        if (!subsExist && movieExist)
        {
                cout << "Subscriber " << subscriberId << " does not exist" << endl;
        }

        if (!movieExist && subsExist)
        {
                cout << "Movie " << movieId << " does not exist" << endl;
        }

        if (!movieExist && !subsExist)
        {
                cout << "Subscriber " << subscriberId << " and movie " << movieId << " do not exist" << endl;
        }

        if (movieExist & (!movieuygun))
        {
                cout << "Movie " << movieId << " has no available copy for renting" << endl;
        }

        if (movieuygun && subsExist)
        {
                movcurr->item.setAction(subscriberId, "not returned"); // MOVIE VE SUBSCRIBER ICIN RETURNED, VE RENTED FARKLI STİİLLERDE
                movcurr->item.movieRented();                           // HATA ÇIKARSA ONLARI KONTROL ET.

                subscurr->item.setAction(movieId, "not returned");
                subscurr->item.movieRentedS();

                cout << "Movie " << movieId << " has been rented by subscriber " << subscriberId << endl;
        }

        // örneğin subscriber 111 film 10 u rentledi.
        //  csubsptr ile subscriber 111 i buldum.
        //  cmovptr ile movie 10 u buldum.

        // eğer movie sistemde varsa, yani bulduysan şimdi kopya sayısını kontrol et. if(>0)
        // rentleyebilirsin.
        // cmovptr-> decrement number of copies. rentMovie() //AvailableCopies--; //originalNumberOfCopy gibi bir değişken.

        // son durumda da action listesini güncelle.

        // csubsptr->setAction(10, not returned);  +
        // cmovptr->setAction(111, not returned);  +

        // aynısı returnMovie için de geçerli

        // subs a rent diye method aç action objesi oluşturup eklesin.
        // filmi sistemden sakın silme bilgileri kaybetmemen gerekiyor.
}
void MovieRentalSystem::returnMovie(const int subscriberId, const int movieId)
{
        // find movie
        bool movieExist = false;
        Node<Movie> *movcurr = MovieHead;

        while (movcurr != nullptr)
        {
                if ((movcurr->item.id) == movieId) // movie var mı? olmayan bir movie i returnlemeye çalışabilir?
                {
                        movieExist = true;
                        break;
                }
                movcurr = movcurr->next;
        }

        // find subscriber
        bool subsExist = false;
        Node<Subscriber> *subscurr = Subshead;

        while (subscurr != nullptr)
        {
                if ((subscurr->item.subscriberId) == subscriberId)
                {
                        subsExist = true;
                        break;
                }
                subscurr = subscurr->next;
        }

        if (movieExist && subsExist)
        {
                if (subscurr->item.ReturnMovie(movieId))
                {
                        movcurr->item.movieReturned(subscriberId);
                        movcurr->item.movieGeldi();
                        cout << "Movie " << movieId << " has been returned by subscriber " << subscriberId << endl;
                }

                else
                {
                        cout << "No rental transaction for subscriber " << subscriberId << " and movie " << movieId << endl;
                }
        }

        // hem movie ye ait rent report hem de o subscribera ait rent report yenilenmeli
        // return diye metod aç action objesini bulup statusu değiştirsin.
}
void MovieRentalSystem::showMoviesRentedBy(const int subscriberId) const
{
        // find subscriber
        bool subsExist = false;
        Node<Subscriber> *subscurr = Subshead;

        while (subscurr != nullptr)
        {
                if ((subscurr->item.subscriberId) == subscriberId)
                {
                        subsExist = true;
                        break;
                }
                subscurr = subscurr->next;
        }

        if (subsExist)
        {
                subscurr->item.printTransactionsOfSubscriber();
        }
        else
        {
                cout << "Subscriber " << subscriberId << " does not exist" << endl;
        }

        // search ile subscriberi bul ve onun transactions listesini yazdır.
        // subscriberin içinde print transactions diye bir metod yaz.
}

void MovieRentalSystem::showSubscribersWhoRentedMovie(const int movieId) const
{
        // find movie
        bool movieExist = false;
        Node<Movie> *movcurr = MovieHead;

        while (movcurr != nullptr)
        {
                if ((movcurr->item.id) == movieId) // movie var mı?
                {
                        movieExist = true;
                        break;
                }
                movcurr = movcurr->next;
        }

        if (movieExist)
        {
                movcurr->item.printTransactionsOfMovie();
        }
        if (!movieExist)
        {
                cout << "Movie " << movieId << " does not exist" << endl;
        }

        // movie ye ait action listesi olcak mı? olcak. movieyi bulıp transaction listesini yazdır.
        // ikinci seçenek olarak sisteme tek bir
        // transactions listesi konulabilir.
}

void MovieRentalSystem::showAllMovies() const
{
        cout << "Movies in the movie rental system:" << endl;
        Node<Movie> *curr = MovieHead;
        while (curr != nullptr)
        {
                curr->item.printMovie();
                curr = curr->next;
        }
}

void MovieRentalSystem::showAllSubscribers() const
{
        cout << "Subscribers in the movie rental system:" << endl;
        Node<Subscriber> *curr = Subshead;
        while (curr != nullptr)
        {
                curr->item.print();
                cout << endl;
                curr = curr->next;
        }
}

/* int main()
{
        MovieRentalSystem mrs;

        mrs.addMovie(5555, 2);
        mrs.addMovie(1111, 1);
        mrs.addMovie(3333, 2);
        mrs.addMovie(2222, 2);

        // mrs.removeMovie(5555);
        // mrs.removeMovie(3333);
        // mrs.removeMovie(1111);
        // mrs.removeMovie(2222);

        mrs.rentMovie(22,3333);
        mrs.rentMovie(11,1111);
        mrs.rentMovie(15,8888);

        mrs.showAllMovies();

        return 0;
}  */
