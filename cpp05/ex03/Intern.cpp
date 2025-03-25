#include "Intern.hpp"

Intern::Intern(void)
{
    std::cout << "an Intern was created" << std::endl;
}

Intern::~Intern()
{
    std::cout << "an Intern was Destroyed" << std::endl;
}

Intern::Intern(Intern &copy)
{
    std::cout << "an Intern was copied" << std::endl;
    *this = copy;
}

Intern const &Intern::operator=(const Intern &copy)
{
    std::cout << "an Assignment operator was called for an Intern" << std::endl;
    return(*this);
}

AForm *Intern::Makeform(std::string name, std::string target)
{
    if (name == "RobotomyRequestForm")
        return(new RobotomyRequestForm(target));
    else if (name == "PresidentialPardonForm")
        return(new PresidentialPardonForm(target));
    else if (name == "ShrubberyCreationForm")
        return(new ShrubberyCreationForm(target));
    else
        std::cout << "Form was not created because form name doesnt exist" << std::endl;
    return(NULL);
}
