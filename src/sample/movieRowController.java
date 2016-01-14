package sample;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.control.ListCell;
import javafx.scene.control.ListView;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.image.ImageViewBuilder;
import javafx.util.Callback;

import java.util.ArrayList;
import java.util.Arrays;

/**
 * Created by roi on 14/01/16.
 */
public class movieRowController {
    String movieCode;
    String movieName;
    int movieLength;
    int movieYear;
    double movieRank;
    String movieTypes;
    String imgUrl;
    String movieDescription;
    ArrayList<ArrayList<String>> staffTypes = new ArrayList<ArrayList<String>>();

    public movieRowController(String movie) {
        ArrayList<String> movieInfoAndStaff = new ArrayList<String>(Arrays.asList(movie.split("\n")));

        ArrayList<String> movieParams = new ArrayList<String>(Arrays.asList(movieInfoAndStaff.get(0).split(" ")));

        this.movieCode = movieParams.get(0);
        this.movieName = movieParams.get(1);
        this.movieLength = Integer.parseInt(movieParams.get(2));
        this.movieYear = Integer.parseInt(movieParams.get(3));
        this.movieRank = Double.parseDouble(movieParams.get(4));

        ArrayList<String> movieTypesList = new ArrayList<String>(Arrays.asList(movieParams.get(5).split(",")));
        StringBuilder strBldr = new StringBuilder("");
        boolean isFirst = true;
        for (int i = 0; i < movieTypesList.size(); ++i) {
            if (isFirst) {
                strBldr.append(movieTypesList.get(i));
                isFirst = false;
            } else {
                strBldr.append(" | " + movieTypesList.get(i));
            }
        }
        this.movieTypes = strBldr.toString();
        this.imgUrl = movieParams.get(6);
        isFirst = true;
        StringBuilder strBldr2 = new StringBuilder("");
        for (int i = 7; i < movieParams.size(); ++i) {
            if (isFirst) {
                strBldr2.append(movieParams.get(i));
                isFirst = false;
            } else {
                strBldr2.append(" " + movieParams.get(i));
            }
        }
        this.movieDescription = strBldr2.toString();

        ArrayList<String> directors = new ArrayList<>();
        directors.add("0");
        directors.add("Directors:");
        this.staffTypes.add(directors);
        ArrayList<String> actors = new ArrayList<>();
        actors.add("1");
        actors.add("Actors:");
        this.staffTypes.add(actors);
        ArrayList<String> screenWriters = new ArrayList<>();
        screenWriters.add("2");
        screenWriters.add("Screen Writers:");
        this.staffTypes.add(screenWriters);
        ArrayList<String> producers = new ArrayList<>();
        producers.add("3");
        producers.add("Producers:");
        this.staffTypes.add(producers);
        String[] professionalInfo;
        for (int i = 1; i < movieInfoAndStaff.size(); ++i) {
            professionalInfo = movieInfoAndStaff.get(i).split(" ");
            for (int j = 0; j < this.staffTypes.size(); ++j) {
                if (professionalInfo[0].equals(this.staffTypes.get(j).get(0))) {
                    this.staffTypes.get(j).add(professionalInfo[1] + " " + professionalInfo[2]);
                    break;
                }
            }
        }
    }
    @FXML
    ImageView imgMovie;

    @FXML
    Label lblMovieTitle;

    @FXML
    Label lblMovieInfo;

    @FXML
    Label lblMovieGoodStars;

    @FXML
    Label lblMovieBadStars;

    @FXML
    Label lblMovieRank;

    @FXML
    Label lblMovieRankFrom;

    @FXML
    Label lblMovieDescrioption;

    @FXML
    ListView lstMovieStaff;

    @FXML
    public void initialize() {
        imgMovie = ImageViewBuilder.create()
                .image(new Image(this.imgUrl))
                .build();

        lblMovieTitle.setText("#" + this.movieCode + " - " + this.movieName + "(" + this.movieYear + ")");
        lblMovieInfo.setText(this.movieLength + " min - " + this.movieTypes);

        int goodStars = (int) this.movieRank;
        StringBuilder strBldr = new StringBuilder("");
        String strGoodString;
        for (int i = 0; i < goodStars; ++i) {
            strBldr.append("★");
        }
        strGoodString = strBldr.toString();
        lblMovieGoodStars.setText(strGoodString);

        int badStars = 10 - goodStars;
        StringBuilder strBldr2 = new StringBuilder("");
        String strBadString;
        for (int i = 0; i < badStars; ++i) {
            strBldr2.append("★");
        }
        strBadString = strBldr2.toString();
        lblMovieBadStars.setText(strBadString);

        lblMovieRank.setText(new Double(this.movieRank).toString());

        lblMovieRankFrom.setText("/10");

        lblMovieDescrioption.setText(this.movieDescription);

        lstMovieStaff.setCellFactory(new Callback<ListView, ListCell>() {
            @Override
            public ListCell call(ListView param) {
                return new MovieStaffListRow();
            }
        });
    }

}
