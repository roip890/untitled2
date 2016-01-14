package sample;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

/**
 * Created by tomericko on 14/01/16.
 */
public class TCPClient {

    private Socket socket;
    private PrintWriter out;
    private BufferedReader in;
    private int port;

    //constructor for the class TCPClient
    public TCPClient(int port){
        this.port = port;
        try{
            this.socket = new Socket("127.0.0.1", port);
            this.out = new PrintWriter(socket.getOutputStream(), true);
            this.in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        }catch (IOException e){
            //System.out.println("Error establishing connection.");
            e.printStackTrace();
        }

    }


    public String commandToServer(String com){
        String result = null , cur = null;
        this.out.println(com);
        try {
            while ((cur = in.readLine()) != null) {
                result += cur + "\n";
            }
        }catch (IOException e){
            e.printStackTrace();
        }

        return result;

    }

    public Socket getSocket() {
        return socket;
    }

    public void setSocket(Socket socket) {
        this.socket = socket;
    }

    public PrintWriter getOut() {
        return out;
    }

    public void setOut(PrintWriter out) {
        this.out = out;
    }

    public BufferedReader getIn() {
        return in;
    }

    public void setIn(BufferedReader in) {
        this.in = in;
    }

    public int getPort() {
        return port;
    }

    public void setPort(int port) {
        this.port = port;
    }
}
