import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/*
 * Created by Nathan Welch on 2/23/2017.
 * Watering Grass
 */
public class main {
    /* greedy approach
       sort into array with least l in front
     */


    public static void main(String[] args) {
        // while not end of file, loop all this stuff

        ArrayList<Integer> integers = new ArrayList<Integer>();
        numS n; //number of sprinklers
        n.

        length l; //length of grass
        width w; //width of grass

        File folder = new File("input.txt");

        try{
            Scanner s = new Scanner(folder);

        }
        catch(IOException ex) {
            System.out.println("No File to open");
        }





        //read in inputs
        try{
            Scanner scanner = new Scanner(new File("input.txt"));
            n.setNumS(scanner.nextInt());
            l.setlength(scanner.nextInt());
            w.setwidth(scanner.nextInt());
//            while(scanner.hasNextInt()){
//                integers.add(scanner.nextInt());
//            }
            scanner.close();
        }
        catch(IOException ex) {
            System.out.println("No File to open");
        }

        System.out.println(nums + "  ")

    }

    private class length {
        int length = 0;
        private int getlength() { return length; }
        private void setlength(int l) {
            length = l;
        }
    }

    private class width {
        int width = 0;
        private int getwidth() { return width; }
        private void setwidth(int w) {
            width = w;
        }
    }


}

