/*
 * Ascent MMORPG Server
 * String Localization Manager
 * Copyright (C) 2007 Burlex <burlex@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef __LOCALIZATIONMGR_H
#define __LOCALIZATIONMGR_H

struct LocalizedCreatureName
{
	char * Name;
	char * SubName;
};

struct LocalizedGameObjectName
{
	char * Name;
};

struct LocalizedNpcText
{
	char * Texts[8];
};

struct LocalizedItem
{
	char * Name;
	char * Description;
};

struct LocalizedQuest
{
	char * Title;
	char * Details;
	char * Objectives;
	char * CompletionText;
	char * IncompleteText;
	char * EndText;
	char * ObjectiveText[4];
};

class LocalizationMgr
{
public:
	void Reload(bool first);
	void Lower(string& conv);
	uint32 GetLanguageId(uint32 full);
	uint32 GetLanguageId(string langstr)
	{
		string ns = langstr;
		Lower(ns);

		uint32 lid = *(uint32*)ns.c_str();
		return GetLanguageId(lid);
	}

	LocalizedQuest *			GetLocalizedQuest(uint32 id, uint32 language);
	LocalizedItem *				GetLocalizedItem(uint32 id, uint32 language);
	LocalizedNpcText *			GetLocalizedNpcText(uint32 id, uint32 language);
	LocalizedCreatureName *		GetLocalizedCreatureName(uint32 id, uint32 language);
	LocalizedGameObjectName *	GetLocalizedGameObjectName(uint32 id, uint32 language);

private:
	HM_NAMESPACE::hash_map<uint32, LocalizedQuest>				* m_Quests;
	HM_NAMESPACE::hash_map<uint32, LocalizedItem>				* m_Items;
	HM_NAMESPACE::hash_map<uint32, LocalizedNpcText>			* m_NpcTexts;
	HM_NAMESPACE::hash_map<uint32, LocalizedCreatureName>		* m_CreatureNames;
	HM_NAMESPACE::hash_map<uint32, LocalizedGameObjectName>		* m_GameObjectNames;
	vector<pair<uint32,uint32> >								  m_languages;
	bool														  m_disabled;
};

extern LocalizationMgr sLocalizationMgr;

#endif