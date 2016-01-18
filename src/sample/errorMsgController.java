package sample;

import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

/**
 * Created by roi on 11/01/16.
 */
public class errorMsgController {
    String tag;
    String msg;

    public errorMsgController(String tag, String msg) {
        this.tag = tag;
        this.msg = msg;
    }

    @FXML
    Label lblError;

    @FXML
    Label titleError;

    @FXML
    Button btnError;

    @FXML
    void initialize(){
        titleError.setText(this.tag);
        lblError.setText(this.msg);
        btnError.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                ((Stage)(btnError.getScene().getWindow())).close();
            }
        });
    }
}
