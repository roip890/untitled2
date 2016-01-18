package sample;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Slider;
import javafx.scene.control.TextField;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

/**
 * Created by roi on 11/01/16.
 */
public class addMovieController {

    @FXML
    TextField txtCode;
    @FXML
    TextField txtMovieName;
    @FXML
    TextField txtLength;
    @FXML
    Slider  sliderRating;
    @FXML
    TextField txtMovieDescription;
    @FXML
    TextField txtYear;
    @FXML
    Button btnAddMovie;
    @FXML
    void initialize(){

        btnAddMovie.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                String com = "1 " + txtCode.getText() + " " + txtMovieName.getText() +" " + txtLength.getText() +
                        " " + txtYear.getText() + " " + String.valueOf(sliderRating.getValue()) +
                        " " + txtMovieDescription.getText();
                String result = TCPClient.getInstance(null, 0).commandToServer(com);
                System.out.println(result);
                ((Stage)btnAddMovie.getScene().getWindow()).close();
            }
        });



    }
}
