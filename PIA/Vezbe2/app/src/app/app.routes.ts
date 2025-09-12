import { Routes } from '@angular/router';
import { AboutComponent } from './about/about.component';
import { WriterComponent } from './writer/writer.component';

export const routes: Routes = [
    {path: "about", component: AboutComponent},
    {path: "writer", component: WriterComponent}
];
