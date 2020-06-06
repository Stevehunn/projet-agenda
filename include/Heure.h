#ifndef HEURE_H
#define HEURE_H


class Heure {
public:
    Heure() = default;
    virtual ~Heure() = default;
    bool operator<(const Heure& right) const { return h_ < right.h_&& m_ < right.m_; }
protected:
private:
    int h_; // Heure
    int m_; // Minute
};

#endif // HEURE_H
