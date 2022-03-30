//https://blog.csdn.net/chenyijun/article/details/103032017
#include <QMap>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>

#include <QDebug>

void QMapToJson()
{
	//===map
    QMap<QString, QVariant> mapData = QMap<QString, QVariant>();
    mapData.insert("id", "3000101");
    mapData.insert("number", "15289705326");
    mapData.insert("name", "Job Bresh");

	//===map to json
    QJsonDocument doc = QJsonDocument::fromVariant(QVariant(mapData));

    QByteArray jsonByteArray = doc.toJson();
    QString jsonString = QString(jsonByteArray);
	qDebug() << "QMap<QString, QVariant> to json: \n" << jsonString;
 
    QByteArray njba = jsonString.toUtf8();
    QJsonObject nobj = QJsonObject(QJsonDocument::fromJson(njba).object());

    //字符串转换后的对象
	qDebug() << "string conversion of object: \n"
             << nobj.take("id").toString() << endl
             << nobj.take("number").toString() << endl
             << nobj.take("name").toString() << endl;
}
 
void JsonToQMap()
{
    //===json
    QJsonObject json;
    json.insert("id", "3000102");
    json.insert("number", "15789705324");
    json.insert("name", "Job Victor");
 
    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);
	qDebug() << strJson;

    //==Json to QMap
    QVariantMap map = json.toVariantMap();
    int numMap = map.size();
    //取值
	qDebug() << "numMap===========" << numMap;
	qDebug() << "map[\"id\"]===========" << map["id"];
	qDebug() << "map[\"id\"].toString()===========" << map["id"].toString();
    //qDebug() << "map.take(\"number\")===========" << map.take("number").toString();
	qDebug() << "map.value(\"name\")===========" << map.value("name").toString();

	for(auto it = map.constBegin(); it!=map.constEnd(); ++it)
	{
		qDebug() << "key:" << it.key() << "  value:" << it.value();
	}
}

int main()
{
	QMapToJson();
	JsonToQMap();
	return 0;
}