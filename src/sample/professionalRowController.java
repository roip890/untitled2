package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Label;

import java.util.ArrayList;

/**
 * Created by roi on 14/01/16.
 */
public class professionalRowController {
    String professionalInfo;
    public professionalRowController(String professionalInfo) {
        this.professionalInfo = professionalInfo;
    }

    @FXML
    Label lblProfessionalInfo;

    @FXML
    public void initialize() {
        lblProfessionalInfo.setText(this.professionalInfo);
    }
}
