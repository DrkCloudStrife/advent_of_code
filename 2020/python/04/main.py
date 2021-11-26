import re

class PasswordValidator(object):
    BIRTH_YEAR = 'byr:(\d+)(?=\s|$)'
    COUNTRY_ID = 'cid:(\d+)(?=\s|$)'
    EXPIRATION_YEAR = 'eyr:(\d+)(?=\s|$)'
    EYE_COLOR = 'ecl:(\w+)(?=\s|$)'
    HAIR_COLOR = 'hcl:(#\w+)(?=\s|$)'
    HEIGHT = 'hgt:(\w+)(?=\s|$)'
    ISSUE_YEAR = 'iyr:(\d+)(?=\s|$)'
    PASSPORT_ID = 'pid:(\d+)(?=\s|$)'

    def __init__(self, data):
        self.passports = []
        self.__reset_valid_passports()
        self.__aggregate_passports(data)

    def validate_pt1(self):
        self.__reset_valid_passports()
        for idx, passport in enumerate(self.passports):
            has_birth_year = "byr" in passport
            has_issue_year = "iyr" in passport
            has_expiration_year = "eyr" in passport
            has_height = "hgt" in passport
            has_hair_color = "hcl" in passport
            has_eye_color = "ecl" in passport
            has_passport_id = "pid" in passport
            has_country_id = "cid" in passport

            is_valid = (
                has_birth_year and
                has_issue_year and
                has_expiration_year and
                has_height and
                has_hair_color and
                has_eye_color and
                has_passport_id
            )

            if is_valid:
                self.valid_passports.append(passport)
            # birth = self.__pattern('BIRTH_YEAR').findall(passport)
            # country = self.__pattern('COUNTRY_ID').findall(passport)
            # expiration = self.__pattern('EXPIRATION_YEAR').findall(passport)
            # eyes = self.__pattern('EYE_COLOR').findall(passport)
            # hair = self.__pattern('HAIR_COLOR').findall(passport)
            # height = self.__pattern('HEIGHT').findall(passport)
            # issued = self.__pattern('ISSUE_YEAR').findall(passport)
            # pid = self.__pattern('PASSPORT_ID').findall(passport)

            # rg_valid = (birth and expiration and eyes and hair and height and issued and pid)

            # if is_valid and not rg_valid:
                # print('passport discrepancy: [{}] {}'.format(idx, passport))
                # print('birth: {}'.format(birth))
                # print('exp: {}'.format(expiration))
                # print('eyes: {}'.format(eyes))
                # print('hair: {}'.format(hair))
                # print('height: {}'.format(height))
                # print('issued: {}'.format(issued))
                # print('pid: {}'.format(pid))
                # print('----')

    def __aggregate_passports(self, data):
        current_passport = ""

        for row in data:
            if row.strip() is '':
                self.passports.append(current_passport.strip())
                current_passport = ""
                continue
            current_passport += row.strip() + ' '

        self.passports.append(current_passport.strip())

    def __pattern(self, pattern_type):
        reg = getattr(self, pattern_type)
        return re.compile(r'{}'.format(reg))

    def __reset_valid_passports(self):
        self.valid_passports = []
