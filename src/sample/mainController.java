package sample;

import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.ListCell;
import javafx.scene.control.ListView;
import javafx.scene.input.MouseEvent;
import javafx.util.Callback;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

public class mainController {

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
    Button btnAdd;

    @FXML
    ListView lstItems;

    @FXML
    void initialize() {
        /*
        String resultFromServer;
        try (
                Socket socket = new Socket("127.0.0.1", 5555);
                PrintWriter out = new PrintWriter(socket.getOutputStream(), true);
                BufferedReader in = new BufferedReader(
                        new InputStreamReader(socket.getInputStream()));
        )
        {
            out.println("1 xyz insep 148 2012 8.8 desc");
            resultFromServer = in.readLine();
            System.out.println(resultFromServer);

        } catch (Exception e){
        }*/


        String url = "https://www.google.co.il/url?sa=i&rct=j&q=&esrc=s&source=images&cd=&cad=rja&uact=8&ved=0ahUKEwj1tteRjqnKAhWJthQKHZN9D-UQjRwIBw&url=http%3A%2F%2Ftrailers.apple.com%2Ftrailers%2Fwb%2Finception%2F&psig=AFQjCNH_3_yoUGc-5694j_8OiM-NEIRKGg&ust=1452854137020065";
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
        btnAdd.setOnMouseClicked(new EventHandler<MouseEvent>() {
        @Override
        public void handle(MouseEvent event) {
            addProfessional addPro = new addProfessional();
            String s = addPro.show();
            System.out.println(s);
        }
        });


        Platform.runLater(new Runnable() {
            @Override
            public void run() {
                btnAdd.requestFocus();
            }
        });
    }
}