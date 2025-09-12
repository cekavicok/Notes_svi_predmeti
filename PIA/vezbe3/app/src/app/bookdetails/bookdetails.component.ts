import { Component, Input, input} from '@angular/core';
import { Book } from '../models/book';

@Component({
  selector: 'app-bookdetails',
  standalone: true,
  imports: [],
  templateUrl: './bookdetails.component.html',
  styleUrl: './bookdetails.component.css'
})
export class BookdetailsComponent {

  @Input() book: Book = new Book()
}
