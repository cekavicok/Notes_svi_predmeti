import { Component, inject, OnInit } from '@angular/core';
import { Book } from '../models/book';
import { BooksService } from '../services/books.service';
import { BookdetailsComponent } from '../bookdetails/bookdetails.component';
import { FormsModule } from '@angular/forms';

@Component({
  selector: 'app-books',
  standalone: true,
  imports: [BookdetailsComponent, FormsModule],
  templateUrl: './books.component.html',
  styleUrl: './books.component.css'
})
export class BooksComponent implements OnInit{

  ngOnInit(): void {
    this.allBooks = this.booksService.getAllBooks()
  }

  allBooks: Book[] = [] //inicijalizovan niz
  private booksService = inject(BooksService) //ubacio servis


  searchParam=""
  searchBooks(){
    this.allBooks = this.booksService.findBooks(this.searchParam)
  }

}
