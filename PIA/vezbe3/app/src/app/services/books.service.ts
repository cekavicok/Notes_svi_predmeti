import { Injectable } from '@angular/core';
import { Book } from '../models/book';

@Injectable({
  providedIn: 'root'
})
export class BooksService {

  constructor() { }

  getAllBooks(): Book[]{
    return [{name: "book1", author: "Petar", pages: 123},
      {name: "book2", author: "Jovan", pages: 321},
      {name: "book3", author: "Vuk", pages: 666}
    ]
  }


  findBooks(searchParam: string): Book[]{
    return this.getAllBooks().filter(
      (book)=>{
        return book.name.includes(searchParam)}
    )
  }
  //OVO JE IDENTICNO JER IMA TRI NACINA DA SE ZAPISE I SVE RADI
  /*findBooks(searchParam: string): Book[]{
    return this.getAllBooks().filter(
      book=>return book.name.includes(searchParam)
    )
  } */
}
