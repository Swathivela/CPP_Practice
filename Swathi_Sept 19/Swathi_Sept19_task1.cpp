#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <algorithm>

class ServiceRecord {
private:
    std::string date_;
    int mileage_;
    std::string description_;

public:
    ServiceRecord() : date_(""), mileage_(0), description_("") {}

       ServiceRecord(const std::string& date, int mileage, const std::string& description)
        : date_(date), mileage_(0), description_(description) {
        if (mileage < 0) throw std::invalid_argument("Mileage must be non-negative");
        mileage_ = mileage;
    }

  
    ServiceRecord(const ServiceRecord& other)
        : date_(other.date_), mileage_(other.mileage_), description_(other.description_) {}

  
    ServiceRecord& operator=(const ServiceRecord& other) {
        if (this != &other) {
            date_ = other.date_;
            mileage_ = other.mileage_;
            description_ = other.description_;
        }
        return *this;
    }


    const std::string& getDate() const { return date_; }
    int getMileage() const { return mileage_; }
    const std::string& getDescription() const { return description_; }

    
    void print() const {
        std::cout << "Date: " << date_
                  << ", Mileage: " << mileage_
                  << ", Description: " << description_ << "\n";
    }
};


class Car {
private:
    std::string vin_;
    std::string make_;
    std::string model_;
    double price_;

    ServiceRecord* serviceHistory_;
    size_t serviceCount_;
    size_t serviceCap_;

    int* damageCodes_;
    size_t damageCount_;
    size_t damageCap_;

    static size_t totalCars_;

    void reserveService(size_t newCap) {
        if (newCap <= serviceCap_) return;
        ServiceRecord* newArr = new ServiceRecord[newCap];
        for (size_t i = 0; i < serviceCount_; ++i) newArr[i] = serviceHistory_[i];
        delete[] serviceHistory_;
        serviceHistory_ = newArr;
        serviceCap_ = newCap;
    }

    void reserveDamage(size_t newCap) {
        if (newCap <= damageCap_) return;
        int* newArr = new int[newCap];
        for (size_t i = 0; i < damageCount_; ++i) newArr[i] = damageCodes_[i];
        delete[] damageCodes_;
        damageCodes_ = newArr;
        damageCap_ = newCap;
    }

public:
   
    Car()
        : vin_(""), make_(""), model_(""), price_(0.0),
          serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
          damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        ++totalCars_;
    }

    Car(const std::string& vin, const std::string& make,
        const std::string& model, double price)
        : vin_(vin), make_(make), model_(model), price_(0.0),
          serviceHistory_(nullptr), serviceCount_(0), serviceCap_(0),
          damageCodes_(nullptr), damageCount_(0), damageCap_(0) {
        if (price < 0) throw std::invalid_argument("Price must be non-negative");
        price_ = price;
        ++totalCars_;
    }

    Car(const Car& other)
        : vin_(other.vin_), make_(other.make_), model_(other.model_), price_(other.price_),
          serviceHistory_(nullptr), serviceCount_(other.serviceCount_), serviceCap_(other.serviceCap_),
          damageCodes_(nullptr), damageCount_(other.damageCount_), damageCap_(other.damageCap_) {
        // Deep copy serviceHistory_
        if (serviceCap_ > 0) {
            serviceHistory_ = new ServiceRecord[serviceCap_];
            for (size_t i = 0; i < serviceCount_; ++i)
                serviceHistory_[i] = other.serviceHistory_[i];
        }
       
        if (damageCap_ > 0) {
            damageCodes_ = new int[damageCap_];
            for (size_t i = 0; i < damageCount_; ++i)
                damageCodes_[i] = other.damageCodes_[i];
        }
        ++totalCars_;
    }


    ~Car() {
        delete[] serviceHistory_;
        delete[] damageCodes_;
        --totalCars_;
    }


    friend void swap(Car& lhs, Car& rhs) noexcept {
        using std::swap;
        swap(lhs.vin_, rhs.vin_);
        swap(lhs.make_, rhs.make_);
        swap(lhs.model_, rhs.model_);
        swap(lhs.price_, rhs.price_);
        swap(lhs.serviceHistory_, rhs.serviceHistory_);
        swap(lhs.serviceCount_, rhs.serviceCount_);
        swap(lhs.serviceCap_, rhs.serviceCap_);
        swap(lhs.damageCodes_, rhs.damageCodes_);
        swap(lhs.damageCount_, rhs.damageCount_);
        swap(lhs.damageCap_, rhs.damageCap_);
    }

 
    Car& operator=(Car other) {
        swap(*this, other);
        return *this;
    }


    static size_t getTotalCars() { return totalCars_; }


    void setVIN(const std::string& vin) { vin_ = vin; }
    void setMake(const std::string& make) { make_ = make; }
    void setModel(const std::string& model) { model_ = model; }
    void setPrice(double price) {
        if (price < 0) throw std::invalid_argument("Price must be non-negative");
        price_ = price;
    }


    const std::string& getVIN() const { return vin_; }
    const std::string& getMake() const { return make_; }
    const std::string& getModel() const { return model_; }
    double getPrice() const { return price_; }
    size_t getServiceCount() const { return serviceCount_; }
    size_t getDamageCount() const { return damageCount_; }
    const ServiceRecord* getServiceHistory() const { return serviceHistory_; }
    const int* getDamageCodes() const { return damageCodes_; }

  
    void addService(const ServiceRecord& rec) {
        if (serviceCount_ == serviceCap_) reserveService(serviceCap_ == 0 ? 2 : serviceCap_ * 2);
        serviceHistory_[serviceCount_++] = rec;
    }

    void addDamageCode(int code) {
        if (damageCount_ == damageCap_) reserveDamage(damageCap_ == 0 ? 2 : damageCap_ * 2);
        damageCodes_[damageCount_++] = code;
    }

    void printInfo() const {
        std::cout << "VIN: " << vin_
                  << ", Make: " << make_
                  << ", Model: " << model_
                  << ", Price: " << price_
                  << ", Services: " << serviceCount_
                  << ", Damages: " << damageCount_ << "\n";
        for (size_t i = 0; i < damageCount_; ++i) {
            std::cout << "  Damage[" << i << "] = " << damageCodes_[i] << "\n";
        }
        for (size_t i = 0; i < serviceCount_; ++i) {
            std::cout << "  Service[" << i << "]: ";
            serviceHistory_[i].print();
        }
    }
};


size_t Car::totalCars_ = 0;

double averagePrice(const Car* arr, size_t n) {
    if (n == 0) return 0.0;
    double sum = 0;
    for (size_t i = 0; i < n; ++i) sum += arr[i].getPrice();
    return sum / n;
}

bool compareByPriceAsc(const Car& a, const Car& b) {
    return a.getPrice() < b.getPrice();
}

bool compareByPriceDesc(const Car& a, const Car& b) {
    return a.getPrice() > b.getPrice();
}

bool areCarsEqual(const Car& a, const Car& b) {
    return a.getVIN() == b.getVIN();
}

const Car* maxPriceCar(const Car* arr, size_t n) {
    if (n == 0) return nullptr;
    const Car* maxC = &arr[0];
    for (size_t i = 1; i < n; ++i)
        if (arr[i].getPrice() > maxC->getPrice()) maxC = &arr[i];
    return maxC;
}

const Car* findCarByVIN(const Car* arr, size_t n, const std::string& vin) {
    for (size_t i = 0; i < n; ++i)
        if (arr[i].getVIN() == vin) return &arr[i];
    return nullptr;
}

size_t countCarsWithDamage(const Car* arr, size_t n, int code) {
    size_t count = 0;
    for (size_t i = 0; i < n; ++i) {
        const int* dmg = arr[i].getDamageCodes();
        for (size_t j = 0; j < arr[i].getDamageCount(); ++j) {
            if (dmg[j] == code) {
                ++count;
                break;
            }
        }
    }
    return count;
}

void swapCars(Car& a, Car& b) {
    swap(a, b);
}


int main() {
    std::cout << "Initial Cars: " << Car::getTotalCars() << "\n";

    Car cDefault;
    cDefault.printInfo();

    Car cParam("1HGCM", "Honda", "Accord", 19999.99);
    cParam.addDamageCode(101);
    cParam.addDamageCode(205);
    cParam.addDamageCode(307);
    cParam.addService(ServiceRecord("2022-03-15", 15000, "Oil change"));
    cParam.addService(ServiceRecord("2023-01-10", 25000, "Brake pads replacement"));
    cParam.printInfo();

    Car cCopy(cParam);
    cCopy.printInfo();

    Car cAssign;
    cAssign = cParam;
    cAssign.printInfo();

    size_t N = 3;
    Car* garage = new Car[N];
    garage[0] = Car("JH4KA", "Acura", "TLX", 27999.49);
    garage[1] = Car("5YJ3E", "Tesla", "Model 3", 39999.00);
    garage[2] = Car("WBA4", "BMW", "3 Series", 34999.99);

    for (size_t i = 0; i < N; ++i) {
        garage[i].addDamageCode(100 + (int)i);
        garage[i].addService(ServiceRecord("2024-02-05", 35000, "Inspection"));
        garage[i].printInfo();
    }

    std::cout << "Average Price: " << averagePrice(garage, N) << "\n";
    const Car* mostExp = maxPriceCar(garage, N);
    if (mostExp) std::cout << "Most Expensive Car VIN: " << mostExp->getVIN() << "\n";

    const Car* found = findCarByVIN(garage, N, "5YJ3E");
    if (found) std::cout << "Found Tesla price: " << found->getPrice() << "\n";

    std::cout << "Cars with damage code 101: " << countCarsWithDamage(garage, N, 101) << "\n";

    delete[] garage;

    std::cout << "Final Cars: " << Car::getTotalCars() << "\n";
    return 0;
}