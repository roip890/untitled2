package sample;

import javafx.application.Platform;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.VBox;
import org.omg.PortableServer.THREAD_POLICY_ID;

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

    Button btnSearch;

    @FXML
    void initialize() {



        btnSearch.setOnMouseClicked(new EventHandler<MouseEvent>() {
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
                btnSearch.requestFocus();
            }
        });
    }
}