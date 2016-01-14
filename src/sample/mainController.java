package sample;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListCell;
import javafx.scene.control.ListView;
import javafx.scene.control.MenuItem;
import javafx.scene.image.ImageView;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.util.Callback;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.ArrayList;

public class mainController {
    private TCPClient client;

    public TCPClient getClient() {
        return client;
    }



    /*
    class MyThread extends Thread {
        @Override
        public void run() {
            System.out.print("before");
            try {
                Thread.sleep(5000);
            } catch (InterruptedException e) {

            }
            System.out.print("after");

            Platform.runLater(new Runnable() {
                @Override
                public void run() {
                    btnLogin.setText("Done");
                }
            });
        }
    }*/
    @FXML
    ImageView imgLogo;

    @FXML
    Button btnAdd;

    @FXML
    MenuItem miAddProfessional;

    @FXML
    MenuItem miAddMovie;

    @FXML
    MenuItem miAllProfessional;

    @FXML
    MenuItem miAllMovie;

    @FXML
    ListView lstItems;

    @FXML
    MenuButton btnMnuSearch;

    @FXML
    MenuItem searchMoviesByProfessional;

    @FXML
    MenuItem searchMovieById;

    @FXML
    MenuItem searchProfessionalsByMovie;


    @FXML
    void initialize() {
        searchMoviesByProfessional.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                btnMnuSearch.setText(searchMoviesByProfessional.getText());
            }
        });

        searchMovieById.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                btnMnuSearch.setText(searchMovieById.getText());
            }
        });

        searchProfessionalsByMovie.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                btnMnuSearch.setText(searchProfessionalsByMovie.getText());
            }
        });

        this.client = new TCPClient(5555);//need to change port

        String url = "http://ia.media-imdb.com/images/M/MV5BMjAxMzY3NjcxNF5BMl5BanBnXkFtZTcwNTI5OTM0Mw@@._V1_SX300.jpg";
        lstItems.getItems().add("xyz Inception 148 2010 8.8 SciFi,Action " + url +" This is the description\n" +
                "1 Ellen Page Ariadne Super-Star\n" +
                "1 Leonardo Dicaprio 42");


        lstItems.setCellFactory(new Callback<ListView, ListCell>() {
            @Override
            public ListCell call(ListView param) {
                return new MovieListRow();
            }
        });


// handle exception

        miAddProfessional.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                addProfessional addPro = new addProfessional();
                String s = addPro.show();
                System.out.println(s);
            }
        });

        miAddMovie.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                addMovie addMov = new addMovie();
                String s = addMov.show();
                System.out.println(s);
            }
        });

        miAllProfessional.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                addProfessional addPro = new addProfessional();
                String s = addPro.show();
                System.out.println(s);
            }
        });

        miAddProfessional.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                addProfessional addPro = new addProfessional();
                String s = addPro.show();
                System.out.println(s);
            }
        });

        imgLogo.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                login con = new login();
                con.show();

            }
        });




        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                btnAdd.requestFocus();
            }
        });



    }







    //Add all professionals retrieved from server to listView
    protected void addAllProToView() {
        lstItems.getItems().clear();
        ArrayList<String> arr = new ArrayList<>();
        String cur = null;
        try {
            while ((cur = TCPClient.getInstance(null,0).getIn().readLine()) != null) {
                lstItems.getItems().add(cur);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    //Add all movies retrieved from server to listView
    protected void addAllMovToView(){
        lstItems.getItems().clear();
        String result = null, cur = null;
        try {
            while ((cur = TCPClient.getInstance(null,0).getIn().readLine()) != null) {
                if(cur.isEmpty()){
                    lstItems.getItems().add(result);
                    result = null;
                    continue;
                }
                result += cur;
            }
        }catch (IOException e){
            e.printStackTrace();
        }
    }
}