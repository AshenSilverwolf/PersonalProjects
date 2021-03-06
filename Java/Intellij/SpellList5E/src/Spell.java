import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Spell {
    private String name;
    private String school;
    private int level;
    private int castingTime;
    private int range;
    private ArrayList<String> components;
    private boolean concentration;
    private boolean ritual;
    private String duration;
    private ArrayList<String> classes;
    private String description;
    private String higherLevel;

    public Spell(String name, String school, int level, int castingTime,
                 int range, ArrayList<String> components, boolean concentration,
                 boolean ritual, String duration, ArrayList<String> classes, String description, String higherLevel) {

        this.name = name;
        this.school = school;
        this.level = level;
        this.castingTime = castingTime;
        this.range = range;
        this.components = components;
        this.concentration = concentration;
        this.ritual = ritual;
        this.duration = duration;
        this.classes = classes;
        this.description = description;
        this.higherLevel = higherLevel;
    }

    public Spell() {
        this("defaultName", "defaultSchool", 0, 0, 0, new ArrayList<>(Arrays.asList("V", "S", "M", "a white feather")),
                true, true, "defaultDuration", new ArrayList<>(Arrays.asList("Wizard")), "defaultDescription", "N/A");
    }

    public void archiveSpell(FileWriter writer) throws IOException {
        writer.write(this.name + "\n");
        writer.write(this.school + "\n");
        writer.write("Level: " + this.level + "\n");
        writer.write("Casting Time: " + this.castingTime + "\n");
        writer.write("Range: " + this.range + "\n");
        boolean material = false;
        for (int i = 0; i < this.components.size(); i++) {
            if (!material && this.components.get(i).compareTo("M") != 0) {
                writer.write(this.components.get(i));
            }
            else if (!material && this.components.get(i).compareTo("M") == 0) {
                writer.write(this.components.get(i) + " (");
                material = true;
            }
            else if (material) {
                writer.write(this.components.get(i) + ")");
            }

            if (!material && i < this.components.size() - 1) {
                writer.write(", ");
            }
        }
        writer.write("\n");
        if (this.ritual)
            writer.write("Ritual\n");
        writer.write("Duration: ");
        if (this.concentration)
            writer.write("Concentration, ");
        writer.write(this.duration + "\n");
        writer.write("Classes: ");
        for (int i = 0; i  < this.classes.size(); i++) {
            writer.write(this.classes.get(i));
            if (i != this.classes.size() - 1) {
                writer.write(", ");
            }
        }
        writer.write("\n");
        writer.write(this.description + "\n");
        writer.write("At Higher Levels: " + this.higherLevel + "\n");
        writer.write("\n");
    }

    public String getName() {
        return this.name;
    }

    public String getSchool() {
        return this.school;
    }

    public int getLevel() {
        return this.level;
    }

    public int getCastingTime() {
        return this.castingTime;
    }

    public int getRange() {
        return this.range;
    }

    public ArrayList<String> getComponents() {
        return this.components;
    }

    public boolean isConcentration() {
        return this.concentration;
    }

    public boolean isRitual() {
        return this.ritual;
    }

    public String getDuration() {
        return this.duration;
    }

    public ArrayList<String> getClasses() {
        return this.classes;
    }

    public String getDescription() {
        return this.description;
    }

    public String getHigherLevel() {
        return this.higherLevel;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSchool(String school) {
        this.school = school;
    }

    public void setLevel(int level) {
        this.level = level;
    }

    public void setCastingTime(int castingTime) {
        this.castingTime = castingTime;
    }

    public void setRange(int range) {
        this.range = range;
    }

    public void setComponents(ArrayList<String> components) {
        this.components = components;
    }

    public void setConcentration(boolean concentration) {
        this.concentration = concentration;
    }

    public void setRitual(boolean ritual) {
        this.ritual = ritual;
    }

    public void setDuration(String duration) {
        this.duration = duration;
    }

    public void setClasses(ArrayList<String> classes) {
        this.classes = classes;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public void setHigherLevel(String higherLevel) {
        this.higherLevel = higherLevel;
    }
}
