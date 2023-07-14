#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[100];
    int year;
};

void modify_book(struct book book);

int main() {
    struct book book;

    strcpy(book.title, "To Kill a Mockingbird");
    strcpy(book.author, "Harper Lee");
    book.year = 1960;

    printf("Before modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    modify_book(&book);

    printf("After modification:\n");
    printf("Title: %s, Author: %s, Year: %d\n", book.title, book.author, book.year);

    return 0;
}

/*
Doesn't work because the `struct book book` in this function isn't the same
as the `struct book book` in main(), so changes aren't reflected back in main().

void modify_book(struct book book) {
    book.year = 1925;
    strcpy(book.title, "The Great Gatsby");
    strcpy(book.author, "F. Scott Fitzgerald");
}
*/


/*
There are two ways to fix i:
*/

/*
1. Returning the struct book:

Note how you need to change the return type from `void` to `struct book`
and have the return line.

struct book modify_book(struct book book) {
    book.year = 1925;
    strcpy(book.title, "The Great Gatsby");
    strcpy(book.author, "F. Scott Fitzgerald");
    return book;
}

Back in the main() function, you would need to modify the line:
> modify_book(book);
to:
> book = modify_book(book);
because modify_book() now returns the updated version of the book,
so you will need to reassign it back to the book in main().
*/

/*
2. Using a struct pointer

Note how you don't need to return anything.

`book` is now a pointer to a type of `struct book`, it will point to the
one in the main() function.
*/
void modify_book(struct book *book) {
    /*
    `*book.year` is not going to work because C is weird and will attemp to 
    evaluate `book.year` first before dereferencing it, which would give an
    error because `book` is a pointer and thus does not have the field `year`.
    */
    /*
    `(*book).year` will work because you're telling it to dereference `book`
    first, which would give you something of type `struct book`, then you will
    atempt to access the `year` field. However, it is a bit annoying to type.
    */
    /*
    `book->year` has the same meaning as `(*book).year` but just neater. The
    stab (->) notation will dereference the struct pointer on the LHS and access
    the field on the RHS.
    */
    book->year = 1925;
    strcpy(book->title, "The Great Gatsby");
    strcpy(book->author, "F. Scott Fitzgerald");
}
