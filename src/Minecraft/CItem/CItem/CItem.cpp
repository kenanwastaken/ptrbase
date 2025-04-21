#include "CItem.h"
#include "../../../Java/JVM/JVM.h"
#include "../../../Java/CField/CField.h"

const char* CItem::GetName()
{
	if (!isValid())
		return "NULL";

	CField field(GetObj(), m_Class.GetFieldID("unlocalizedName", "Ljava/lang/String;"));
	if (!field.isValid())
		return "NULL";

	jstring jstr = field.GetString();
	if (jstr == nullptr)
		return "NULL";

	const char* name = JVM::GetInstance().m_Env->GetStringUTFChars(jstr, 0);
	if (name == nullptr)
		return "NULL";

	JVM::GetInstance().m_Env->ReleaseStringUTFChars(jstr, name);
	return name;
}