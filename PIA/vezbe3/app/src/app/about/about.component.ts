import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-about',
  standalone: true,
  imports: [],
  templateUrl: './about.component.html',
  styleUrl: './about.component.css'
})
export class AboutComponent implements OnInit{
  ngOnInit(): void {
    this.description = "About page"
  }
  description = "" //inicijalizovace se nakon sto se uradi komponenta
  imgPath = "image/lotr.jpg"


}
