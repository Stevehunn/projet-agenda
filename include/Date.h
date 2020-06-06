#ifndef DATE_H
#define DATE_H


class Date {
public:
    Date();
    virtual ~Date();
    bool operator<(const Date& right) const { return a_ < right.a_&& m_ < right.m_&& j_ < right.j_; }

protected:
private:
    int a_; // Anné
    int m_; // Mois
    int j_; // Jour
};

#endif // DATE_H
