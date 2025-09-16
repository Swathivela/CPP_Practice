#include <iostream>
#include <iomanip>
#include <string>

using namespace std;



enum ComponentType
{
    COMPONENT_TYPE_ENGINE,
    COMPONENT_TYPE_AVIONICS,
    COMPONENT_TYPE_LANDING_GEAR,
    COMPONENT_TYPE_FUEL_SYSTEM
};

enum ComponentStatus
{
    COMPONENT_STATUS_OPERATIONAL,
    COMPONENT_STATUS_MAINTENANCE_REQUIRED,
    COMPONENT_STATUS_FAILED
};


string type_to_string(ComponentType t)
{
    switch (t)
    {
    case COMPONENT_TYPE_ENGINE: return "Engine";
    case COMPONENT_TYPE_AVIONICS: return "Avionics";
    case COMPONENT_TYPE_LANDING_GEAR: return "Landing Gear";
    case COMPONENT_TYPE_FUEL_SYSTEM: return "Fuel System";
    default: return "Unknown";
    }
}

string status_to_string(ComponentStatus s)
{
    switch (s)
    {
    case COMPONENT_STATUS_OPERATIONAL: return "Operational";
    case COMPONENT_STATUS_MAINTENANCE_REQUIRED: return "Maintenance Required";
    case COMPONENT_STATUS_FAILED: return "Failed";
    default: return "Unknown";
    }
}


class AerospaceComponent
{
private:
    int component_identifier;
    double component_efficiency;
    string component_manufacturer;
    ComponentType component_type;
    ComponentStatus component_status;

public:
  
    AerospaceComponent(int id, double efficiency, const string &manufacturer,
                       ComponentType type, ComponentStatus status)
        : component_identifier(id),
          component_efficiency(efficiency),
          component_manufacturer(manufacturer),
          component_type(type),
          component_status(status) {}


    AerospaceComponent()
    {
        cout << "Component " << component_identifier << " destroyed." << endl;
    }

   
    int get_identifier() const { return component_identifier; }
    double get_efficiency() const { return component_efficiency; }
    string get_manufacturer() const { return component_manufacturer; }
    ComponentType get_type() const { return component_type; }
    ComponentStatus get_status() const { return component_status; }

 
    void set_identifier(int id) { component_identifier = id; }
    void set_efficiency(double eff) { component_efficiency = eff; }
    void set_manufacturer(const string &m) { component_manufacturer = m; }
    void set_type(ComponentType t) { component_type = t; }
    void set_status(ComponentStatus s) { component_status = s; }

    void UpdateStatus()
    {
        if (component_efficiency < 50.0)
        {
            component_status = COMPONENT_STATUS_FAILED;
        }
        else if (component_efficiency < 80.0)
        {
            component_status = COMPONENT_STATUS_MAINTENANCE_REQUIRED;
        }
        else
        {
            component_status = COMPONENT_STATUS_OPERATIONAL;
        }
    }

  
    void SimulateUsage(int usage_hours)
    {
        for (int i = 0; i < usage_hours; i++)
        {
            component_efficiency -= (component_efficiency * 0.005); 
            if (component_efficiency < 0.0)
            {
                component_efficiency = 0.0;
                break;
            }
        }
        UpdateStatus();
    }

 
    void PerformMaintenanceCheck() const
    {
        switch (component_status)
        {
        case COMPONENT_STATUS_OPERATIONAL:
            cout << "Component " << component_identifier << " is operational." << endl;
            break;
        case COMPONENT_STATUS_MAINTENANCE_REQUIRED:
            cout << "Component " << component_identifier << " requires maintenance soon." << endl;
            break;
        case COMPONENT_STATUS_FAILED:
            cout << "Component " << component_identifier << " has failed!" << endl;
            break;
        default:
            cout << "Unknown status." << endl;
            break;
        }
    }

  
    void BoostEfficiency()
    {
        while (component_efficiency < 100.0)
        {
            component_efficiency += 1.0;
        }
        if (component_efficiency > 100.0)
        {
            component_efficiency = 100.0;
        }
        UpdateStatus();
    }

    
    void DisplayDetails() const
    {
        cout << "ID: " << component_identifier << endl;
        cout << "Efficiency: " << component_efficiency << "%" << endl;
        cout << "Manufacturer: " << component_manufacturer << endl;
        cout << "Type: " << type_to_string(component_type) << endl;
        cout << "Status: " << status_to_string(component_status) << endl;
        cout << "-----------------------------" << endl;
    }
};



void AssignManufacturer(AerospaceComponent &component, const string &manufacturer_name)
{
    component.set_manufacturer(manufacturer_name);
    cout << "Manufacturer assigned: " << manufacturer_name << endl;
}

bool IsEfficient(const AerospaceComponent &component)
{
    return component.get_efficiency() > 85.0;
}

bool IsSameType(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return componentA.get_type() == componentB.get_type();
}

bool IsSameStatus(const AerospaceComponent &componentA, const AerospaceComponent &componentB)
{
    return componentA.get_status() == componentB.get_status();
}

void PrintFormattedComponentList(const AerospaceComponent component_list[], const int list_size)
{
    cout << left << setw(8) << "ID"
         << setw(12) << "Efficiency"
         << setw(20) << "Manufacturer"
         << setw(15) << "Type"
         << setw(20) << "Status" << endl;
    cout << string(75, '-') << endl;

    for (int i = 0; i < list_size; i++)
    {
        cout << left << setw(8) << component_list[i].get_identifier()
             << setw(12) << component_list[i].get_efficiency()
             << setw(20) << component_list[i].get_manufacturer()
             << setw(15) << type_to_string(component_list[i].get_type())
             << setw(20) << status_to_string(component_list[i].get_status()) << endl;
    }
}

int SearchComponentByIdentifier(const AerospaceComponent component_list[], const int list_size, const int search_identifier)
{
    for (int i = 0; i < list_size; i++)
    {
        if (component_list[i].get_identifier() == search_identifier)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    AerospaceComponent component_one(101, 92.5, "GE Aviation", COMPONENT_TYPE_ENGINE, COMPONENT_STATUS_OPERATIONAL);
    AerospaceComponent component_two(102, 45.0, "Honeywell", COMPONENT_TYPE_AVIONICS, COMPONENT_STATUS_FAILED);
    AerospaceComponent component_three;

    AerospaceComponent components[3] = {component_one, component_two, component_three};

    int choice;
    do
    {
        cout << "\nAerospace Component Monitoring System Menu:\n";
        cout << "1. Add/Update Component Details\n";
        cout << "2. Assign Manufacturer\n";
        cout << "3. Simulate Usage\n";
        cout << "4. Boost Efficiency\n";
        cout << "5. Perform Maintenance Check\n";
        cout << "6. Compare Components\n";
        cout << "7. Search by Component ID\n";
        cout << "8. Display All Components\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int index, id, type_sel, status_sel;
            double efficiency;
            string manufacturer;

            cout << "Enter index (0-2): ";
            cin >> index;
            if (index < 0 || index >= 3)
            {
                cout << "Invalid index!\n";
                continue;
            }

            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter efficiency (0-100): ";
            cin >> efficiency;
            if (efficiency < 0.0 || efficiency > 100.0)
            {
                cout << "Invalid efficiency!\n";
                continue;
            }
            cin.ignore();
            cout << "Enter Manufacturer: ";
            getline(cin, manufacturer);
            if (manufacturer.empty())
            {
                cout << "Manufacturer cannot be empty!\n";
                continue;
            }
            cout << "Enter Type (0=Engine,1=Avionics,2=Landing Gear,3=Fuel System): ";
            cin >> type_sel;
            cout << "Enter Status (0=Operational,1=Maintenance,2=Failed): ";
            cin >> status_sel;

            components[index] = AerospaceComponent(id, efficiency, manufacturer,
                                                   static_cast<ComponentType>(type_sel),
                                                   static_cast<ComponentStatus>(status_sel));
        }
        else if (choice == 2)
        {
            int index;
            string manufacturer;
            cout << "Enter index (0-2): ";
            cin >> index;
            cin.ignore();
            cout << "Enter new Manufacturer: ";
            getline(cin, manufacturer);
            if (index >= 0 && index < 3 && !manufacturer.empty())
            {
                AssignManufacturer(components[index], manufacturer);
            }
        }
        else if (choice == 3)
        {
            int index, hours;
            cout << "Enter index (0-2): ";
            cin >> index;
            cout << "Enter usage hours: ";
            cin >> hours;
            if (index >= 0 && index < 3)
            {
                components[index].SimulateUsage(hours);
            }
        }
        else if (choice == 4)
        {
            int index;
            cout << "Enter index (0-2): ";
            cin >> index;
            if (index >= 0 && index < 3)
            {
                components[index].BoostEfficiency();
            }
        }
        else if (choice == 5)
        {
            int index;
            cout << "Enter index (0-2): ";
            cin >> index;
            if (index >= 0 && index < 3)
            {
                components[index].PerformMaintenanceCheck();
            }
        }
        else if (choice == 6)
        {
            int a, b;
            cout << "Enter two indices (0-2): ";
            cin >> a >> b;
            if (a >= 0 && a < 3 && b >= 0 && b < 3)
            {
                cout << "Same Type? " << (IsSameType(components[a], components[b]) ? "Yes" : "No") << endl;
                cout << "Same Status? " << (IsSameStatus(components[a], components[b]) ? "Yes" : "No") << endl;
            }
        }
        else if (choice == 7)
        {
            int id;
            cout << "Enter component ID to search: ";
            cin >> id;
            int result = SearchComponentByIdentifier(components, 3, id);
            if (result != -1)
            {
                cout << "Component found at index " << result << endl;
            }
            else
            {
                cout << "Component not found!" << endl;
            }
        }
        else if (choice == 8)
        {
            PrintFormattedComponentList(components, 3);
        }

    } while (choice != 9);

    return 0;
}
