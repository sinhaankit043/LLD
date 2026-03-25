#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/* ---------- Interfaces ---------- */


//use below cmd to run c++ file in its directory
//clang++ -std=c++17 bookmyshow.cpp -o bookmyshow && ./bookmyshow

class IMovies;
class ICustomer;

class ITheatre {
public:
    virtual void addMovies(IMovies* movie) = 0;
    virtual void removeMovies(IMovies* movie) = 0;
    virtual void allotSeat(ICustomer* customer, int row, int col) = 0;
    virtual void vacateSeat(ICustomer* customer) = 0;
    virtual ~ITheatre() {}
};

class IMovies {
public:
    virtual void releaseMovie(string name) = 0;
    virtual void expireMovie(string name) = 0;
    virtual void getAllMovies() = 0;
    virtual ~IMovies() {}
};

class ICustomer {
public:
    virtual void watch() = 0;
    virtual void selectMovie(string name) = 0;
    virtual void selectSeat(int row, int col) = 0;
    virtual void displayMovies() = 0;
    virtual ~ICustomer() {}
};

/* ---------- Theatre ---------- */

class Theatre : public ITheatre {
public:
    string name;
    int rows, cols;
    vector<vector<int>> seats;
    vector<IMovies*> movies;
    unordered_map<ICustomer*, pair<int,int>> seatMap;

    Theatre(string name, int r, int c) {
        this->name = name;
        rows = r;
        cols = c;
        seats = vector<vector<int>>(rows, vector<int>(cols, 0));
    }

    void addMovies(IMovies* movie) override {
        if (find(movies.begin(), movies.end(), movie) == movies.end()) {
            movies.push_back(movie);
        }
    }

    void removeMovies(IMovies* movie) override {
        movies.erase(remove(movies.begin(), movies.end(), movie), movies.end());
    }

    void allotSeat(ICustomer* customer, int r, int c) override {
        if (seats[r][c] == 1) {
            cout << "Seat already booked\n";
            return;
        }
        seats[r][c] = 1;
        seatMap[customer] = {r, c};
        cout << "Seat allotted at (" << r << "," << c << ")\n";
    }

    void vacateSeat(ICustomer* customer) override {
        if (seatMap.count(customer)) {
            auto [r, c] = seatMap[customer];
            seats[r][c] = 0;
            seatMap.erase(customer);
            cout << "Seat vacated\n";
        }
    }
};

/* ---------- Movie ---------- */

class Movie : public IMovies {
public:
    vector<string> movieList;

    void releaseMovie(string name) override {
        movieList.push_back(name);
    }

    void expireMovie(string name) override {
        movieList.erase(remove(movieList.begin(), movieList.end(), name),
                        movieList.end());
    }

    void getAllMovies() override {
        cout << "Available Movies:\n";
        for (auto &m : movieList) {
            cout << "- " << m << endl;
        }
    }
};

/* ---------- Customer ---------- */

class Customer : public ICustomer {
public:
    string name;
    IMovies* movie;
    ITheatre* theatre;
    string selectedMovie;

    Customer(string name, IMovies* movie, ITheatre* theatre) {
        this->name = name;
        this->movie = movie;
        this->theatre = theatre;
    }

    void displayMovies() override {
        movie->getAllMovies();
    }

    void selectMovie(string name) override {
        selectedMovie = name;
        cout << this->name << " selected movie: " << name << endl;
    }

    void selectSeat(int r, int c) override {
        theatre->allotSeat(this, r, c);
    }

    void watch() override {
        cout << name << " is watching " << selectedMovie << endl;
         theatre->vacateSeat(this);
    }
};

/* ---------- Main ---------- */

int main() {
    IMovies *movieService=new Movie();
    movieService->releaseMovie("Inception");
    movieService->releaseMovie("Interstellar");

    ITheatre *theatre= new Theatre ("PVR", 5, 5);

    ICustomer *c1= new Customer ("Ankit",movieService , theatre);

    c1->displayMovies();
    c1->selectMovie("Inception");
    c1->selectSeat(2, 3);
    
    c1->watch();
    
      ICustomer *c2= new Customer ("Aman",movieService , theatre);
       c2->selectSeat(2, 3);
      

    return 0;
}
