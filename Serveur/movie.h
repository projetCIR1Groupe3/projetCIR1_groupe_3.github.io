#ifndef _MOVIE_H_
#define _MOVIE_H_

struct Movie{
    unsigned int length;
    char* title;
    char* genre;
    char* directorName;
};

//PROJETC_MOVIE_H

struct Movie* createMovie(unsigned int length, char* title, char* genre, char* directorName);

char* getTitle(struct Movie* m);

char* getGenre(struct Movie* m);

unsigned int getLength(struct Movie* m);

char* getDirectorName(struct Movie* m);

void deleteMovie(struct Movie** m);

#endif




