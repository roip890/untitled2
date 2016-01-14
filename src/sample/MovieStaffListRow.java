package sample;

import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.control.ListCell;

import java.io.IOException;
import java.util.ArrayList;

/**
 * Created by roi on 14/01/16.
 */
public class MovieStaffListRow extends ListCell<ArrayList<String>> {

    @Override
    protected void updateItem(ArrayList<String> staffItem, boolean empty) {
        super.updateItem(staffItem,empty);

        if (staffItem != null) {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("movieStaffRow.fxml"));
            //movieStaffRowController controller = new movieStaffRowController(staffItem);
            //loader.setController(controller);

            Parent root = null;
            try{
                root = loader.load();
            } catch (IOException E) {

            }

            setGraphic(root);
        }
    }

}