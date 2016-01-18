package sample;

import javafx.fxml.FXML;
import javafx.scene.control.ListView;
import javafx.scene.control.RadioButton;
import javafx.scene.control.ToggleGroup;

/**
 * Created by roi on 08/01/16.
 */
public class addProfessionalController {

    @FXML
    ListView lstItems;

    @FXML
    RadioButton radioBtnMale;

    @FXML
    RadioButton radioBtnFamale;

    @FXML
    public void initialize() {

// handle exception

        }
        //lstItems.getItems().addAll("aaaaaaaaaaa", "bbbbbbbbbbbbb", "ggggggggggggggg");
        /*
        lstItems.setCellFactory(new Callback<ListView, ListCell>() {
            @Override
            public ListCell call(ListView param) {
                return new MyListRow();
            }
        });
    }*/
}
