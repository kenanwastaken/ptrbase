#include "CEntityPlayer.h"
#include "../../../Java/JVM/JVM.h"
#include "../../../Java/CMethod/CMethod.h"

CItemStack CEntityPlayer::GetItemStackInUse()
{
    return CItemStack(CMethod(GetObj(), m_Class.GetMethodID("getItemInUse", "()Lnet/minecraft/item/ItemStack;")).GetObj());
}

CItemStack CEntityPlayer::GetHeldItem()
{
    if (!isValid())
        return CItemStack(NULL);

    return CItemStack(CMethod(GetObj(), m_Class.GetMethodID("getHeldItem", "()Lnet/minecraft/item/ItemStack;")).GetObj());
}

const char* CEntityPlayer::GetName()
{
	CMethod method(GetObj(), m_Class.GetMethodID("getName", "()Ljava/lang/String;"));
	if (!method.isValid())
		return "NULL";

	jstring jstr = method.GetString();
	if (jstr == nullptr)
		return "NULL";

	const char* name = JVM::GetInstance().m_Env->GetStringUTFChars(jstr, 0);
	if (name == nullptr)
		return "NULL";

	JVM::GetInstance().m_Env->ReleaseStringUTFChars(jstr, name);

	return name;
}
