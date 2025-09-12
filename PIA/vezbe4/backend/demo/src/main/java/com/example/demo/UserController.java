package com.example.demo;

import java.util.ArrayList;
import java.util.List;

import org.springframework.web.bind.annotation.RestController;

import jakarta.annotation.PostConstruct;
//slusa zahteve koje stizu i odgovara na te zahteve
@RestController
public class UserController {
    
    private List<User> allUsers;


    @PostConstruct //nakon sto se izvrsi konstrukor ovo ce se samo uraditi lol
    private void init() {
        this.allUsers = new ArrayList<>();
        this.allUsers.add(new User("pera", "pera123", "pera", "peric" ));
        this.allUsers.add(new User("zika", "zika123", "zika", "zikic" ));
        this.allUsers.add(new User("mika", "mika123", "mika", "mikic" ));
    }

    public List<User> getAllUsers(){
        return this.allUsers;
    }

}
