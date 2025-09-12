import { Routes } from '@angular/router';
import { AboutComponent } from './about/about.component';
import { WriterComponent } from './writer/writer.component';
import { BooksComponent } from './books/books.component';
import { BookdetailsComponent } from './bookdetails/bookdetails.component';

export const routes: Routes = [
    {path: "about", component: AboutComponent},
    {path: "writer", component: WriterComponent},
    {path: "b", component: BooksComponent}
];
