/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccartman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 17:25:50 by ccartman          #+#    #+#             */
/*   Updated: 2022/04/23 12:38:49 by ccartman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("Noname"), grade(lowest_grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
	: name(other.name), grade(other.grade) {}

Bureaucrat::Bureaucrat(const std::string &name_, const int grade_)
	: name(name_)
{
	if (grade_ < 1)
		throw GradeTooHighException();
	else if (grade_ > 150)
		throw GradeTooLowException();
	else
		grade = grade_;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	grade = other.grade;

	return *this;
}

Bureaucrat &Bureaucrat::operator++(void)
{
	if (grade == highest_grade)
		throw GradeTooHighException();
	else
		--grade;

	return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat tmp = *this;
	if (grade == highest_grade)
		throw GradeTooHighException();
	else
		grade--;

	return tmp;
}

Bureaucrat &Bureaucrat::operator--(void)
{
	if (grade == lowest_grade)
		throw GradeTooLowException();
	else
		++grade;

	return *this;
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat tmp = *this;
	if (grade == lowest_grade)
		throw GradeTooHighException();
	else
		grade++;

	return tmp;
}

const std::string &Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return "The grade exceeded the maximum value";
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return "The grade exceeded the minimum value";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bur)
{
	out << bur.getName() << ", bureaucrat grade " << bur.getGrade();

	return out;
}
