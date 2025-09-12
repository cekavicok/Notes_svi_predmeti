import { Component, inject, OnInit } from '@angular/core';
import { Writer } from '../models/writer';
import { WriterService } from '../services/writer.service';
import { DatePipe } from '@angular/common';

@Component({
  selector: 'app-writer',
  standalone: true,
  imports: [DatePipe],
  templateUrl: './writer.component.html',
  styleUrl: './writer.component.css'
})
export class WriterComponent implements OnInit  {
  private writerService = inject(WriterService)

  ngOnInit(): void {
    this.allWriters = this.writerService.getAllWriters()
  }

  allWriters: Writer[] = []

  sortByAwards(){
    this.allWriters = this.writerService.sortByAwards()
  }

  sortByBirthday(){
    this.allWriters = this.writerService.sortByDate()
  }

}
