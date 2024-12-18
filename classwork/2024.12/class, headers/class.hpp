class student {
    private:
    std::string _name;
    int _age;

    public:
    student(std::string, int);

    int getAge();

    void setAge(int);

    std::string getName();

    void setName(std::string);
};