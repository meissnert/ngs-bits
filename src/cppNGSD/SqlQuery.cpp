#include <QSqlError>
#include "SqlQuery.h"
#include "Exceptions.h"

SqlQuery::SqlQuery(QSqlDatabase db)
	: QSqlQuery(db)
{
}

void SqlQuery::exec(const QString& query)
{
	bool success = QSqlQuery::exec(query);
	if (!success)
	{
		THROW(DatabaseException, "SQL query error: " + lastError().text());
	}
}