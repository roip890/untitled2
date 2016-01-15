package sample;

import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.Group;
import javafx.scene.control.*;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;

/**
 * Created by roi on 08/01/16.
 */
public class addProfessionalController {
    int profession = 0;
    @FXML
    ListView lstItems;

    @FXML
    RadioButton radioBtnMale;

    @FXML
    RadioButton radioBtnFamale;

    @FXML
    Button btnCancleAddProfession;

    @FXML
    Button btnAddProfession;

    @FXML
    Button btnAddPro;
    @FXML
    TextField txtProID;
    @FXML
    TextField txtAge;
    @FXML
    TextField txtProName;
    @FXML
    MenuButton mbtnProfession;
    @FXML
    MenuItem proDirector;
    @FXML
    MenuItem proActor;
    @FXML
    MenuItem proWriter;
    @FXML
    MenuItem proProducer;
    @FXML
    RadioButton radioMale;
    @FXML
    RadioButton radioFemale;
    @FXML
    TextField txtDescription;
    @FXML
    ToggleGroup gender;
    @FXML
    public void initialize() {

        btnAddProfession.setOnMouseClicked(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                StringBuilder toSend = new StringBuilder();
                toSend.append("2 ");
                toSend.append(profession);
                toSend.append(" ");
                toSend.append(txtProID.getText());
                toSend.append(" ");
                toSend.append(txtAge.getText());
                toSend.append(" ");
                toSend.append(txtDescription.getText());
                toSend.append(" ");
                toSend.append(((RadioButton)gender.getSelectedToggle()).getText());
                toSend.append(" ");
                toSend.append(txtProName.getText());
                TCPClient.getInstance(null, 0).commandToServer(toSend.toString());
            }
        });

        proActor.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                mbtnProfession.setText(proActor.getText());
                profession = 1;
            }
        });

        proDirector.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                mbtnProfession.setText(proDirector.getText());
                profession = 0;
            }
        });
        proProducer.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                mbtnProfession.setText(proProducer.getText());
                profession = 3;
            }
        });
        proWriter.setOnAction(new EventHandler<ActionEvent>() {
            @Override
            public void handle(ActionEvent event) {
                mbtnProfession.setText(proWriter.getText());
                profession = 2;
            }
        });


    }
}
