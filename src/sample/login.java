package sample;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Modality;
import javafx.stage.Stage;

import java.io.IOException;

/**
 * Created by tomericko on 14/01/16.
 */
public class login {

    public void show() {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("login.fxml"));
        Stage stage = new Stage();
        Parent root = null;
        try {
            root = FXMLLoader.load(getClass().getResource("login.fxml"));

        } catch (IOException e) {
            e.printStackTrace();
        }
        Scene scene = new Scene(root, 250, 150);
        //scene.getStylesheets().add(getClass().getResource("addProfessional.css").toExternalForm());
        stage.setScene(scene);
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.showAndWait();
    }



}
