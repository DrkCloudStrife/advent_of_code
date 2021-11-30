import re

class PasswordValidator(object):
    REQUIRED_FIELDS = {
        'byr': 'byr:(\d{4})(?=\s|$)',
        'eyr': 'eyr:(\d{4})(?=\s|$)',
        'ecl': 'ecl:(\w+)(?=\s|$)',
        'hcl': 'hcl:(#(?:[0-9a-fA-F]{3}){1,2})(?=\s|$)',
        'hgt': 'hgt:(\w+)(?=\s|$)',
        'iyr': 'iyr:(\d{4})(?=\s|$)',
        'pid': 'pid:(\d{9})(?=\s|$)'
    }

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

    def validate_pt2(self):
        self.__reset_valid_passports()
        for passport in self.passports:
            validity = []
            for key in list(self.REQUIRED_FIELDS):
                is_valid = self.__validate(key, passport)
                validity.append(is_valid)
            if all(validity):
                self.valid_passports.append(passport)

    def __aggregate_passports(self, data):
        current_passport = ""

        for row in data:
            if row.strip() is '':
                self.passports.append(current_passport.strip())
                current_passport = ""
                continue
            current_passport += row.strip() + ' '

        self.passports.append(current_passport.strip())

    def __validate_byr(self,value):
        value = int(value)
        if value >= 1920 and value <= 2002:
            return True
        return False

    def __validate_eyr(self,value):
        value = int(value)
        if value >= 2020 and value <= 2030:
            return True
        return False

    def __validate_ecl(self,value):
        if value in ['amb','blu','brn','gry','grn','hzl','oth']:
            return True
        return False

    def __validate_hcl(self,value):
        return True

    def __validate_hgt(self,value):
        regx = r'^([0-9]+)(cm|in)'
        if re.search(regx, value):
            size, metric = re.findall(regx, value)[0]
            size = int(size)
            if metric == 'cm':
                return size >= 150 and size <= 193
            elif metric == 'in':
                return size >= 59 and size <= 76
        return False

    def __validate_iyr(self,value):
        value = int(value)
        if value >= 2010 and value <= 2020:
            return True
        return False

    def __validate_pid(self,value):
        return len(value) == 9

    def __validate(self, field, passport):
        regx_str = self.REQUIRED_FIELDS[field]
        regx = re.compile(r'{}'.format(regx_str))
        values = regx.findall(passport)
        if len(values) is 0:
            return False
        validator = getattr(self,'_PasswordValidator__validate_{}'.format(field))
        return validator(values[0])

    def __reset_valid_passports(self):
        self.valid_passports = []
