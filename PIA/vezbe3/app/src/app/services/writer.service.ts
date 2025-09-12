import { Injectable } from '@angular/core';
import { Writer } from '../models/writer';

@Injectable({
  providedIn: 'root'
})
export class WriterService {

  constructor() { }

  getAllWriters(): Writer[]{
    return [{firstname: "Goran", lastname: "djordjevic", awards: 6, birthday: new Date("1997.7.9")},
            {firstname: "Pera", lastname: "petrovic", awards: 5, birthday: new Date("1998.7.9")},
            {firstname: "Jovanka", lastname: "Jolic", awards: 9999, birthday: new Date("1999.7.9")}
    ]
  }
  sortByAwards(): Writer[]{
    return this.getAllWriters().sort((w1,w2)=>{
      return w1.awards-w2.awards
    })
  }
  sortByDate(): Writer[]{
    return this.getAllWriters().sort((w1,w2)=>{
      if(w1.birthday<w2.birthday){
        return -1
      }
      else{
        if(w1.birthday>w2.birthday){
          return 1
        }
        else{
          return 0;
        }
      }
    })
  }
}
