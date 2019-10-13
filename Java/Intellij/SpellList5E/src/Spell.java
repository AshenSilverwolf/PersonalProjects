import java.util.ArrayList;
import java.util.Arrays;

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
    private String description;

    public Spell(String name, String school, int level, int castingTime,
                 int range, ArrayList<String> components, boolean concentration,
                 boolean ritual, String duration, String description) {

        this.name = name;
        this.school = school;
        this.level = level;
        this.castingTime = castingTime;
        this.range = range;
        this.components = components;
        this.concentration = concentration;
        this.ritual = ritual;
        this.duration = duration;
        this.description = description;
    }

    public Spell() {
        this("defaultName", "defaultSchool", 0, 0, 0, new ArrayList<>(Arrays.asList("V", "S", "M")),
                false, false, "defaultDuration", "defaultDescription");
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

    public String getDescription() {
        return this.description;
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

    public void setDescription(String description) {
        this.description = description;
    }
}
