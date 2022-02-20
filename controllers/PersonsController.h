#pragma once

#include <drogon/HttpController.h>
#include "../models/Person.h"

using namespace drogon;
using namespace drogon_model::org_chart;

class PersonsController:public drogon::HttpController<PersonsController>
{
  public:
    METHOD_LIST_BEGIN
			ADD_METHOD_TO(PersonsController::newPerson, "/persons/", Post); // path is /persons/
		  ADD_METHOD_TO(PersonsController::index,"/persons/", Get); //path is /persons/list
		  ADD_METHOD_TO(PersonsController::getPerson,"/persons/{1}", Get); //path is /persons/{arg1}
      ADD_METHOD_TO(PersonsController::updatePerson,"/persons/{1}", Put); //path is /persons/list
      ADD_METHOD_TO(PersonsController::deletePerson,"/persons/{1}", Delete); //path is /persons/list
    METHOD_LIST_END

    void index(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) const;
    void getPerson(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int pPersonId) const;
    void newPerson(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback, Person &&pNewPerson) const;
		void updatePerson(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback, int pPersonId, Person &&pPersonDetails) const;
    void deletePerson(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback, int pPersonId) const;
};