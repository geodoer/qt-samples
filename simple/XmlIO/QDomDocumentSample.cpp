#include<QDomDocument>

#include<QTextStream>
#include<QFile>

#include<iostream>

void Write(const QString& xmlFp)
{
	QDomDocument doc;

	QDomElement menu = doc.createElement("RibbonMenu");
	doc.appendChild(menu);

	for(auto i :
		{
			1,2
		})
	{
		auto page = doc.createElement("RibbonPage");
		page.setAttribute("title", "Page" + QString::number(i));

		for(QString j :
			{ 'A','B','C'
			})
		{
			auto group = doc.createElement("RibbonGroup");
			group.setAttribute("title", "Group+" + j);

			for(QString z :
				{ "undo", "redo"
				})
			{
				QDomElement command = doc.createElement("Command");
				command.setAttribute("title", z + "_t");
				command.setAttribute("command", z);
				command.setAttribute("icon", z + ".png");
				group.appendChild(command);
			}

			page.appendChild(group);
		}

		menu.appendChild(page);
	}

	QFile fileIn(xmlFp);

	if(!fileIn.open(QIODevice::WriteOnly | QIODevice::Text))
	{
		return;
	}

	QTextStream in(&fileIn);
	doc.save(in, 4);
	fileIn.close();
}

void Read(const QString& xmlFp)
{
	QDomDocument doc;
	QFile file(xmlFp);

	if(!file.open(QIODevice::ReadOnly))
	{
		return;
	}

	if(!doc.setContent(&file))
	{
		file.close();
		return;
	}

	file.close();

	//RibbonMenu
	QDomElement docElem = doc.documentElement();
	std::cout << qPrintable(docElem.tagName()) << std::endl;
	
	for(QDomNode n = docElem.firstChild(); !n.isNull(); n = n.nextSibling())
	{
		QDomElement e = n.toElement();

		if(e.isNull())
		{
			continue;
		}

		std::cout << qPrintable(e.tagName()) << " " << qPrintable(e.attribute("title")) << std::endl; // the node really is an element.
	}
}

int main()
{
	QString xmlFp = "menu.xml";

	Write(xmlFp);
	Read(xmlFp);

	return 0;
}